cmake_minimum_required(VERSION 3.0)

set(VERSION 1.0.0)
# set(EAPULSE_VERSION_MAJOR 1)

project(DDSEXPERIMENTS VERSION ${VERSION})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

if(ASAN)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
elseif(TSAN)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
endif()


find_package(fastrtps REQUIRED)

add_subdirectory(video_publisher_dynamic)
add_subdirectory(video_publisher_static)
add_subdirectory(video_subscriber_static)
add_subdirectory(generic_subscriber)
add_subdirectory(msgs)
