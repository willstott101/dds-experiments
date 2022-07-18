#include "./subscriber.h"
#include <chrono>
#include <thread>

#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/attributes/SubscriberAttributes.h>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>
#include <fastdds/dds/subscriber/qos/DataReaderQos.hpp>

using namespace eprosima::fastdds::dds;

VideoSubscriber::VideoSubscriber()
    : participant(nullptr)
    , subscriber(nullptr)
    , topic(nullptr)
    , reader(nullptr)
    , type(new VideoFrameFixedPubSubType())
{
}

bool VideoSubscriber::init()
{
    DomainParticipantQos pqos = PARTICIPANT_QOS_DEFAULT;
    pqos.name("Participant_sub");
    auto factory = DomainParticipantFactory::get_instance();

    participant = factory->create_participant(0, pqos);

    if (participant == nullptr)
    {
        return false;
    }

    //REGISTER THE TYPE
    type.register_type(participant);

    //CREATE THE SUBSCRIBER
    SubscriberQos sqos = SUBSCRIBER_QOS_DEFAULT;

    subscriber = participant->create_subscriber(sqos, nullptr);

    if (subscriber == nullptr)
    {
        return false;
    }

    //CREATE THE TOPIC
    TopicQos tqos = TOPIC_QOS_DEFAULT;

    topic = participant->create_topic(
        "HelloWorldTopic",
        type.get_type_name(),
        tqos);

    if (topic == nullptr)
    {
        return false;
    }

    // CREATE THE READER
    DataReaderQos rqos = subscriber->get_default_datareader_qos();
    rqos.history().depth = 32;
    rqos.reliability().kind = RELIABLE_RELIABILITY_QOS;
    rqos.durability().kind = TRANSIENT_LOCAL_DURABILITY_QOS;

    reader = subscriber->create_datareader(topic, rqos, &listener);

    if (reader == nullptr)
    {
        return false;
    }

    return true;
}

VideoSubscriber::~VideoSubscriber()
{
    if (reader != nullptr)
    {
        subscriber->delete_datareader(reader);
    }
    if (topic != nullptr)
    {
        participant->delete_topic(topic);
    }
    if (subscriber != nullptr)
    {
        participant->delete_subscriber(subscriber);
    }
    DomainParticipantFactory::get_instance()->delete_participant(participant);
}

void VideoSubscriber::SubListener::on_subscription_matched(
        DataReader*,
        const SubscriptionMatchedStatus& info)
{
    if (info.current_count_change == 1)
    {
        matched = info.total_count;
        std::cout << "VideoSubscriber matched." << std::endl;
    }
    else if (info.current_count_change == -1)
    {
        matched = info.total_count;
        std::cout << "VideoSubscriber unmatched." << std::endl;
    }
    else
    {
        std::cout << info.current_count_change
                  << " is not a valid value for SubscriptionMatchedStatus current count change" << std::endl;
    }
}

void VideoSubscriber::SubListener::on_data_available(
        DataReader* reader)
{
    FASTDDS_SEQUENCE(DataSeq, VideoFrameFixed);

    std::cout << " == on_data_available == " << std::endl;

    DataSeq data;
    SampleInfoSeq infos;
    uint16_t firstNum = 0;
    uint16_t lastNum = 0;
    if (ReturnCode_t::RETCODE_OK == reader->read(data, infos))
    {
        std::cout << " (copied " << data.has_ownership() << ")" << std::endl;

        // Iterate over each LoanableCollection in the SampleInfo sequence
        for (LoanableCollection::size_type i = 0; i < infos.length(); ++i)
        {
            // Check whether the DataSample contains data or is only used to communicate of a
            // change in the instance
            if (infos[i].valid_data)
            {
                const VideoFrameFixed& sample = data[i];

                lastNum = sample.data()[0];

                if (i == 0) {
                    firstNum = lastNum;
                    std::cout << "  first is " << firstNum << " from time " << infos[i].source_timestamp  << std::endl;
                }
            }
        }
        std::cout << "  " << infos.length() << " sample received [" << firstNum << ", " << lastNum << "]" << std::endl;


        if (infos[0].valid_data) {
            for (uint16_t i = 0; i <= 3; i++) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "  ... later first says " << (uint16_t)data[0].data()[0] << " at " << &(data[0]) << "" << " from time " << infos[0].source_timestamp  << std::endl;
            }
        }

        // Indicate to the DataReader that the application is done accessing the collection of
        // data values and SampleInfo, obtained by some earlier invocation of read or take on the
        // DataReader.
        reader->return_loan(data, infos);
    }
}

void VideoSubscriber::run()
{
    std::cout << "VideoSubscriber running. Please press enter to stop the VideoSubscriber" << std::endl;
    std::cin.ignore();
}

void VideoSubscriber::run(
        uint32_t number)
{
    std::cout << "VideoSubscriber running until " << number << "samples have been received" << std::endl;
    while (number > listener.samples)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}