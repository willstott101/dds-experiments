class Publisher {

}

template <class T = DynamicData>
class Subscriber {
    Subscriber(
        onDiscover: std::function<std::function<void(T)>(s: Subscribable)>
    );
    Subscriber(
        topics: std::vector<std::string>,
        typeName: std::string,
        onData: std::function<void(T)>
    );
};

