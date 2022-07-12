add_executable(vid_pub_dynamic
  publisher.cpp
  main.cpp
)

target_link_libraries(vid_pub_dynamic
  msgs
  fastrtps
)
