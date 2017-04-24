cmake_minimum_required(VERSION 3.6)
project(Homework2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp sequence.cpp sequence.h)
add_executable(Homework2 ${SOURCE_FILES})