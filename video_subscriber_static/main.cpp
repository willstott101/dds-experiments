#include <iostream>
#include "subscriber.h"

int main(int argc, char** argv) {
    std::cout << "Starting subscriber." << std::endl;

    auto subscriber = VideoSubscriber();
    if (!subscriber.init())
        return 1;

    subscriber.run();

    return 0;
}
