

cmake_minimum_required(VERSION 2.8)
project (Profiler CXX)

message(STATUS "CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}")


set(CMAKE_CXX_FLAGS "-std=c++11")



add_subdirectory(src)
add_executable(profiler_bin src/client.cc)
target_link_libraries(profiler_bin profilerlib)