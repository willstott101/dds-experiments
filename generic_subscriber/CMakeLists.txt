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
