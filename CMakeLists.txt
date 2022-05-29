cmake_minimum_required(VERSION 3.20)
project(logowl)

set(CMAKE_CXX_STANDARD 20)

include_directories(owlib)

add_subdirectory(owlib)
add_subdirectory(my_http_log_monitor)
add_subdirectory(test)