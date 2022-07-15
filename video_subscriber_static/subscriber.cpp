#include "./subscriber.h"

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
    DataReaderQos rqos = DATAREADER_QOS_DEFAULT;
    rqos.reliability().kind = RELIABLE_RELIABILITY_QOS;

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
    SampleInfo info;
    if (reader->take_next_sample(&hello_, &info) == ReturnCode_t::RETCODE_OK)
    {
        if (info.instance_state == ALIVE_INSTANCE_STATE)
        {
            samples++;
            // Print your structure data here.
            std::cout << "Message " << hello_.message() << " " << hello_.index() << " RECEIVED" << std::endl;
        }
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