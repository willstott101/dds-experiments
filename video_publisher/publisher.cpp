# include "./publisher.h"

#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/attributes/PublisherAttributes.h>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/publisher/qos/PublisherQos.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/qos/DataWriterQos.hpp>
#include <fastrtps/types/DynamicDataHelper.hpp>
#include <fastrtps/types/DynamicDataFactory.h>
#include <fastrtps/types/DynamicTypeBuilderPtr.h>
#include <fastrtps/types/DynamicTypeBuilderFactory.h>

#include <thread>
#include <chrono>

using namespace eprosima;

VideoFramePublisher::VideoFramePublisher(
        fastdds::dds::TypeSupport type_,
        fastrtps::types::DynamicData_ptr frame_,
        fastdds::dds::DomainParticipant* participant_,
        fastdds::dds::Publisher* publisher_,
        fastdds::dds::Topic* topic_,
        fastdds::dds::DataWriter* writer_,
        PubListener listener_
) : type(type_),
    frame(frame_),
        participant(participant_),
        publisher(publisher_),
        topic(topic_),
        writer(writer_),
        listener(listener_) {
    // frame.format("RGB888");
    frame->set_string_value("RGB888", 0);
}

VideoFramePublisher::~VideoFramePublisher() {
    publisher->delete_datawriter(writer);
    participant->delete_publisher(publisher);
    participant->delete_topic(topic);
    auto factory = fastdds::dds::DomainParticipantFactory::get_instance();
    factory->delete_participant(participant);
}

VideoFramePublisher VideoFramePublisher::createPublisher() {
    fastdds::dds::DomainParticipantQos pqos = fastdds::dds::PARTICIPANT_QOS_DEFAULT;
    pqos.name("Participant_pub");
    auto factory = fastdds::dds::DomainParticipantFactory::get_instance();

    // if (use_env)
    // {
    //     factory->load_profiles();
    //     factory->get_default_participant_qos(pqos);
    // }

    auto participant = factory->create_participant(0, pqos);

    if (participant == nullptr)
    {
        throw std::runtime_error("Could not create DomainParticipant");
    }

    // fastrtps::types::DynamicData* m_DynHello;
    fastrtps::types::DynamicPubSubType dynType;

    auto typefac = fastrtps::types::DynamicTypeBuilderFactory::get_instance();
    fastrtps::types::DynamicType_ptr char_type = typefac->create_char8_type();
    fastrtps::types::DynamicTypeBuilder_ptr builder = typefac->create_sequence_builder(char_type);
    fastrtps::types::DynamicType_ptr sequence_type = builder->build();

    fastrtps::types::DynamicTypeBuilder_ptr builder2 = typefac->create_sequence_builder(sequence_type);
    fastrtps::types::DynamicType_ptr sequence2_type = builder2->build();

    fastrtps::types::DynamicTypeBuilder_ptr struct_type_builder(typefac->create_struct_builder());
    struct_type_builder->add_member(0, "format", typefac->create_string_type());
    struct_type_builder->add_member(1, "data", sequence2_type);
    struct_type_builder->set_name("VideoFrame");
    fastrtps::types::DynamicType_ptr dynTypePtr = struct_type_builder->build();
    dynType.SetDynamicType(dynTypePtr);
    fastrtps::types::DynamicData_ptr dynMsg(fastrtps::types::DynamicDataFactory::get_instance()->create_data(dynTypePtr));

    fastdds::dds::TypeSupport type(dynType);
    // REGISTER THE TYPE
    // fastdds::dds::TypeSupport type(new VideoFramePubSubType());
    type.get()->auto_fill_type_information(false);
    type.get()->auto_fill_type_object(true);
    type.register_type(participant);

    // CREATE THE PUBLISHER
    fastdds::dds::PublisherQos pubqos = fastdds::dds::PUBLISHER_QOS_DEFAULT;

    // if (use_env)
    // {
    //     participant_->get_default_publisher_qos(pubqos);
    // }

    auto publisher = participant->create_publisher(
        pubqos,
        nullptr);

    if (publisher == nullptr)
    {
        factory->delete_participant(participant);
        throw std::runtime_error("Could not create publisher");
    }

    // CREATE THE TOPIC
    fastdds::dds::TopicQos tqos = fastdds::dds::TOPIC_QOS_DEFAULT;

    // if (use_env)
    // {
    //     participant_->get_default_topic_qos(tqos);
    // }

    auto topic = participant->create_topic(
        "HelloWorldTopic",
        type.get_type_name(),
        tqos);

    if (topic == nullptr)
    {
        participant->delete_publisher(publisher);
        factory->delete_participant(participant);
        throw std::runtime_error("Could not create topic");
    }

    // CREATE THE WRITER
    fastdds::dds::DataWriterQos wqos = fastdds::dds::DATAWRITER_QOS_DEFAULT;

    // if (use_env)
    // {
    //     publisher_->get_default_datawriter_qos(wqos);
    // }

    auto listener = PubListener();

    auto writer = publisher->create_datawriter(
        topic,
        wqos,
        &listener);

    if (writer == nullptr)
    {
        participant->delete_topic(topic);
        participant->delete_publisher(publisher);
        factory->delete_participant(participant);
        throw std::runtime_error("Could not create DataWriter");
    }

    return VideoFramePublisher(type, dynMsg, participant, publisher, topic, writer, listener);
}

void VideoFramePublisher::PubListener::on_publication_matched(
    fastdds::dds::DataWriter*,
    const fastdds::dds::PublicationMatchedStatus& info)
{
    if (info.current_count_change == 1)
    {
        matched = info.total_count;
        std::cout << "Publisher matched." << std::endl;
    }
    else if (info.current_count_change == -1)
    {
        matched = info.total_count;
        std::cout << "Publisher unmatched." << std::endl;
    }
    else
    {
        std::cout << info.current_count_change
                  << " is not a valid value for PublicationMatchedStatus current count change" << std::endl;
    }
}

void VideoFramePublisher::runThread(uint32_t sleep_us)
{
    while (!stop)
    {
        if (publish())
        {
            std::cout << "Message sent" << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::microseconds(sleep_us));
    }
}

void VideoFramePublisher::runForever(uint32_t sleep_us)
{
    stop = false;
    std::thread thread(&VideoFramePublisher::runThread, this, sleep_us);
    std::cout << "Publisher running. Please press enter to stop the Publisher at any time." << std::endl;
    std::cin.ignore();
    stop = true;
    thread.join();
}

bool VideoFramePublisher::publish() {
    if (listener.matched > -1)
    {
        fastrtps::types::DynamicData* seq = frame->loan_value(1);
        if (seq->get_item_count() == 0) {
            fastrtps::types::MemberId mId;
            seq->insert_sequence_data(mId);
            std::cout << "insert_sequence_data: " << mId << std::endl;
            seq->insert_sequence_data(mId);
            std::cout << "insert_sequence_data: " << mId << std::endl;
            fastrtps::types::DynamicData* seq2 = seq->loan_value(mId);
            std::cout << "loan_value: " << seq2 << std::endl;
            seq2->insert_char8_value('1', mId);
            seq2->insert_char8_value('2', mId);
            seq2->insert_char8_value('3', mId);
            seq2->insert_char8_value('4', mId);
            seq->return_loaned_value(seq2);
        } else {
            // seq->set_char8_value('1', seq->get_member_id_at_index(0));
        }
        frame->return_loaned_value(seq);
        // frame.data({'1', '2', '3', '4'});
        writer->write(frame.get());
        std::cout << "Message written" << std::endl;
        fastrtps::types::DynamicDataHelper::print(frame);
        return true;
    }
    return false;
}
