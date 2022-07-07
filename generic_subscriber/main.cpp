#include <iostream>
#include "subscriber.h"

int main(int argc, char** argv) {
    std::cout << "Starting subscriber." << std::endl;

    // auto subscriber = GenericSubscriber::createSubscriber();
    // subscriber.runForever(1000 /* us */);

    HelloWorldSubscriber mysub;
    if (mysub.init())
    {
        mysub.run();
    }

    return 0;
}
