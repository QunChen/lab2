cmake_minimum_required(VERSION 3.3)
project(lab2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES basketball.cpp competition.h competition.cpp)
add_executable(lab2 ${SOURCE_FILES})