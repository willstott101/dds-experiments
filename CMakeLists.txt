cmake_minimum_required(VERSION 3.0)

set(VERSION 1.0.0)
# set(EAPULSE_VERSION_MAJOR 1)

project(DDSEXPERIMENTS VERSION ${VERSION})

# if(CMAKE_FIND_ROOT_PATH)
#  message("Using CMAKE_FIND_ROOT_PATH: ${CMAKE_FIND_ROOT_PATH}")
# else()
#  set(CMAKE_FIND_ROOT_PATH /opt/tritium)
# endif()

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
add_subdirectory(generic_subscriber)
add_subdirectory(msgs)

# add_library(eapulse SHARED
#   src/pulseaudio.cpp
#   src/context.cpp
# )

# set_target_properties(eapulse PROPERTIES
#   VERSION ${VERSION}
#   SOVERSION ${EAPULSE_VERSION_MAJOR}
#   LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
# )

# target_link_libraries(eapulse
#   EaCommon::eacommon
#   PkgConfig::libpulse
#   )

# target_include_directories(eapulse
#     PUBLIC
#         $<INSTALL_INTERFACE:include>
#         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#     PRIVATE
#         ${CMAKE_CURRENT_SOURCE_DIR}/src
# )

# # if (NOT NO_TESTS)
# # include(CTest)
# # enable_testing()
# # add_subdirectory("test")
# # endif()

# set(CMAKE_INSTALL_PREFIX /opt/tritium)

# INSTALL (TARGETS eapulse DESTINATION lib)
# INSTALL (DIRECTORY ${CMAKE_SOURCE_DIR}/include  DESTINATION .)
# INSTALL (FILES ${CMAKE_SOURCE_DIR}/cmake/modules/EaPulseConfig.cmake DESTINATION lib/cmake/EaPulse)
# INSTALL (FILES ${CMAKE_SOURCE_DIR}/ld.so.conf.d/x86_64-eapulse.conf  DESTINATION /etc/ld.so.conf.d)

# install(TARGETS eapulse
#     EXPORT libeapulse-export
#     LIBRARY DESTINATION lib
#     ARCHIVE DESTINATION lib
# )

# install(EXPORT libeapulse-export
#   FILE
#     EaPulseTargets.cmake
#   NAMESPACE
#     EaPulse::
#   DESTINATION
#     lib/cmake/EaPulse
# )
