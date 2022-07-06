add_library(publisher_lib
  msgs/video_framePubSubTypes.cxx
  msgs/video_frame.cxx
  publisher.cpp
)

target_link_libraries(publisher_lib
  fastrtps
)

add_executable(publisher
  main.cpp
)

target_link_libraries(publisher
  publisher_lib
)
