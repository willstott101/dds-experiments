#include <iostream>
#include "publisher.h"

int main(int argc, char** argv) {
    std::cout << "Starting publisher." << std::endl;

    auto publisher = VideoFramePublisher::createPublisher();
    publisher.runForever(100000 /* us */);

    return 0;
}
