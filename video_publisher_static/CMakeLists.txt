add_executable(vid_pub_static
  publisher.cpp
  main.cpp
)

target_link_libraries(vid_pub_static
  msgs
  fastrtps
)
