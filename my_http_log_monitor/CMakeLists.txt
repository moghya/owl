cmake_minimum_required(VERSION 3.20)
project(logowl)

set(CMAKE_CXX_STANDARD 20)

add_library(my_http_log_monitor_lib
            http_log_parsed_data_holder.cpp
            report_http_stats_rule.cpp
            traffic_period_threshold_rule.cpp
            my_http_log_monitor.cpp)
target_link_libraries(my_http_log_monitor_lib logowl_lib)
