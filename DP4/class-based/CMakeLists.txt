cmake_minimum_required(VERSION 4.0)
project(DP4)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(DP4
        main.cpp
        include/hangPerson.h
        cpp/selectWord.cpp
        cpp/displayGallow.cpp
        cpp/displayWord.cpp
        cpp/gameInput.cpp
        cpp/HangPerson.cpp)
