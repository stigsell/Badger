cmake_minimum_required(VERSION 3.6)
project(badger)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Player.cpp Player.h Location.cpp Location.h Graph.cpp Graph.h Schedule.cpp Schedule.h)
add_executable(badger ${SOURCE_FILES})