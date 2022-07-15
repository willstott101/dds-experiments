add_executable(vid_sub_static
  subscriber.cpp
  main.cpp
)

target_link_libraries(vid_sub_static
  msgs
  fastrtps
)
