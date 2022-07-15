#include <iostream>
#include "publisher.h"

int main(int argc, char** argv) {
    std::cout << "Starting publisher." << std::endl;

    // 1024 messages is over 6.37GiB of buffer
    auto publisher = VideoFramePublisher::createPublisher(1024);
    publisher.runForever(100000 /* us */);

    return 0;
}
