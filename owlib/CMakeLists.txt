cmake_minimum_required(VERSION 3.20)
project(logowl)

set(CMAKE_CXX_STANDARD 17)

add_library(logowl_lib
                utils.cpp
                invalid_argument_exception.cpp
                alert.cpp
                owl.cpp
                logowl.cpp
                http_logowl.cpp
                owl_builder.cpp)

add_subdirectory(test)