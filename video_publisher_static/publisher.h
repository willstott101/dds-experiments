#include "../msgs/ExamplesPubSubTypes.h"
#include <fastdds/dds/publisher/DataWriterListener.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>

using namespace eprosima;

class VideoFramePublisher
{
public:
    virtual ~VideoFramePublisher();

    void runForever(uint32_t sleep_us);

    fastdds::dds::TypeSupport type;

    static VideoFramePublisher createPublisher();

private:
    class PubListener : public fastdds::dds::DataWriterListener
    {
    public:

        PubListener()
            : matched(0)
        {
        }

        ~PubListener() override
        {
        }

        void on_publication_matched(
            fastdds::dds::DataWriter* writer,
            const fastdds::dds::PublicationMatchedStatus& info) override;

        int matched;
    };

    VideoFramePublisher(
        fastdds::dds::TypeSupport type,
        fastdds::dds::DomainParticipant* participant,
        fastdds::dds::Publisher* publisher,
        fastdds::dds::Topic* topic,
        fastdds::dds::DataWriter* writer,
        PubListener listener
    );

    VideoFrame frame;

    fastdds::dds::DomainParticipant* participant;
    fastdds::dds::Publisher* publisher;
    fastdds::dds::Topic* topic;
    fastdds::dds::DataWriter* writer;
    PubListener listener;

    std::atomic<bool> stop;

    void runThread(uint32_t sleep_us);
    bool publish();
};
