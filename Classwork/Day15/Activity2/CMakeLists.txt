cmake_minimum_required(VERSION 4.1)
project(Activity2)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)



add_executable(Activity2
        testing.cpp
        include/converter.h
        converter.cpp)
