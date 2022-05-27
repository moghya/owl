cmake_minimum_required(VERSION 3.20)
project(logowl)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(owlib)
add_executable(logowl main.cpp)
target_link_libraries(logowl owlib)