add_library(subscriber_lib
  subscriber.cpp
)

target_link_libraries(subscriber_lib
  fastrtps
)

add_executable(subscriber
  main.cpp
)

target_link_libraries(subscriber
  subscriber_lib
)

add_library(dyn_publisher_lib
  publisher.cpp
)

target_link_libraries(dyn_publisher_lib
  fastrtps
)

add_executable(dyn_publisher
  mainpub.cpp
)

target_link_libraries(dyn_publisher
  dyn_publisher_lib
)

