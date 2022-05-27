cmake_minimum_required(VERSION 3.20)
project(logowl)

set(CMAKE_CXX_STANDARD 17)

add_executable(logowl_tester http_logowl_tester.cpp)
target_link_libraries(logowl_tester logowl_lib)
