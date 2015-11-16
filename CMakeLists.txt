cmake_minimum_required(VERSION 3.3)
project(node_argon2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(/home/samuelm/n/include/node lib/src)
set(SOURCE_FILES src/main.cpp src/argon2_wrapper.h src/argon2_wrapper.cpp src/argon2_wrapper.h)

add_executable(node_argon2 ${SOURCE_FILES})
