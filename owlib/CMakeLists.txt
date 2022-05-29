cmake_minimum_required(VERSION 3.20)
project(logowl)

set(CMAKE_CXX_STANDARD 20)

add_library(logowl_lib
            utils.cpp
            reader/log_reader.cpp
            reader/file_log_reader.cpp
            parser/log_parser.cpp
            parser/csv_log_parser.cpp
            exception/invalid_argument_exception.cpp
            rule/process_log_rule.cpp
            alert/alert.cpp
            owl/owl.cpp
            owl/logowl.cpp
        owl/owl_builder.cpp
)
