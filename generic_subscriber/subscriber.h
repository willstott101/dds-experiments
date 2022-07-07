#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/domain/DomainParticipantListener.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/qos/DataReaderQos.hpp>
#include <fastrtps/subscriber/SampleInfo.h>
#include <fastrtps/rtps/common/Types.h>

#include <fastrtps/types/TypeIdentifier.h>
#include <fastrtps/types/TypeObject.h>

#include <fastrtps/attributes/SubscriberAttributes.h>

#include <map>

using namespace eprosima;

class HelloWorldSubscriber
{
public:

    HelloWorldSubscriber();

    virtual ~HelloWorldSubscriber();

    //!Initialize the subscriber
    bool init();

    //!RUN the subscriber
    void run();

    //!Run the subscriber until number samples have been received.
    void run(
            uint32_t number);

private:

    fastdds::dds::DomainParticipant* mp_participant;

    fastdds::dds::Subscriber* mp_subscriber;

    std::map<fastdds::dds::DataReader*, fastdds::dds::Topic*> topics_;

    std::map<fastdds::dds::DataReader*, fastrtps::types::DynamicType_ptr> readers_;

    std::map<fastdds::dds::DataReader*, fastrtps::types::DynamicData_ptr> datas_;

    fastrtps::SubscriberAttributes att_;

    fastdds::dds::DataReaderQos qos_;

public:

    class SubListener
        :  public fastdds::dds::DomainParticipantListener
    {
    public:

        SubListener(
                HelloWorldSubscriber* sub)
            : n_matched(0)
            , n_samples(0)
            , subscriber_(sub)
        {
        }

        ~SubListener() override
        {
        }

        void on_data_available(
                fastdds::dds::DataReader* reader) override;

        void on_subscription_matched(
                fastdds::dds::DataReader* reader,
                const fastdds::dds::SubscriptionMatchedStatus& info) override;

        void on_type_discovery(
                fastdds::dds::DomainParticipant* participant,
                const fastrtps::rtps::SampleIdentity& request_sample_id,
                const fastrtps::string_255& topic,
                const fastrtps::types::TypeIdentifier* identifier,
                const fastrtps::types::TypeObject* object,
                fastrtps::types::DynamicType_ptr dyn_type) override;

        int n_matched;

        uint32_t n_samples;

        HelloWorldSubscriber* subscriber_;

    }
    m_listener;

};