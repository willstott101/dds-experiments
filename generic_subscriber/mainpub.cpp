#include <iostream>
#include "publisher.h"

int main(int argc, char** argv) {
    std::cout << "Starting publisher." << std::endl;

    // auto subscriber = GenericSubscriber::createSubscriber();
    // subscriber.runForever(1000 /* us */);

    HelloWorldPublisher mysub;
    if (mysub.init())
    {
        mysub.run(2000, 200);
    }

    return 0;
}
