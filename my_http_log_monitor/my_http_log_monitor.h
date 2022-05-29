//
// Created by Shubham Sawant on 28/05/22.
//

#ifndef LOGOWL_MY_HTTP_LOG_MONITOR_H
#define LOGOWL_MY_HTTP_LOG_MONITOR_H

#include <string>

#include "../owlib/parser/csv_log_parser.h"
#include "../owlib/reader/file_log_reader.h"
#include "../owlib/owl/logowl.h"
#include "../owlib/owl/owl_builder.h"

#include "http_log_parsed_data_holder.h"

namespace my {
    class MyHTTPLogMonitor {
        public:
            MyHTTPLogMonitor(const std::string& logFilePath,
                             int reportStatTimerSeconds,
                             int trafficCheckSeconds,
                             int trafficCheckThreshold);
            ~MyHTTPLogMonitor();

            void Start() {
                m_httpLogOwl->Start();
            }

            void Stop() {
                m_httpLogOwl->Stop();
            }

        private:
            moghya::LogOwl* m_httpLogOwl;
            std::unique_ptr<moghya::Owl> m_owlPtr;
    };
}


#endif //LOGOWL_MY_HTTP_LOG_MONITOR_H
