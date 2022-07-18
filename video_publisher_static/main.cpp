#include <iostream>
#include "publisher.h"

int main(int argc, char** argv) {
    std::cout << "Starting publisher." << std::endl;

    // 1024 messages is over 6.37GiB of buffer (max allowed by fastdds afaict is 4.295GB)
    auto publisher = VideoFramePublisher::createPublisher(32);
    publisher.runForever(50000 /* us */);

    return 0;
}
