#include "../msgs/ExamplesPubSubTypes.h"

#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/subscriber/DataReaderListener.hpp>
#include <fastrtps/subscriber/SampleInfo.h>
#include <fastdds/dds/core/status/SubscriptionMatchedStatus.hpp>

class VideoSubscriber
{
public:

    VideoSubscriber();

    virtual ~VideoSubscriber();

    // Initialize the subscriber
    bool init();

    // Run subscriber forever
    void run();

    // Run the subscriber until number samples have been received.
    void run(uint32_t number);

private:

    eprosima::fastdds::dds::DomainParticipant* participant;

    eprosima::fastdds::dds::Subscriber* subscriber;

    eprosima::fastdds::dds::Topic* topic;

    eprosima::fastdds::dds::DataReader* reader;

    eprosima::fastdds::dds::TypeSupport type;

    class SubListener : public eprosima::fastdds::dds::DataReaderListener
    {
    public:

        SubListener()
            : matched(0)
            , samples(0)
        {
        }

        ~SubListener() override
        {
        }

        void on_data_available(
                eprosima::fastdds::dds::DataReader* reader) override;

        void on_subscription_matched(
                eprosima::fastdds::dds::DataReader* reader,
                const eprosima::fastdds::dds::SubscriptionMatchedStatus& info) override;

        int matched;

        uint32_t samples;
    }
    listener;
};