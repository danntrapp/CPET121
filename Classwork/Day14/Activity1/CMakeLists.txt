cmake_minimum_required(VERSION 4.0)
project(Activity1)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Activity1
        include/parts.h
        testing.cpp
        whole.cpp
        fraction.cpp
        ../../Testing/testing1.cpp)
