//
// Created by Shubham Sawant on 28/05/22.
//

#ifndef LOGOWL_MY_HTTP_LOG_MONITOR_H
#define LOGOWL_MY_HTTP_LOG_MONITOR_H

#include <memory>
#include <string>

#include "../owlib/owl/logowl.h"
#include "../owlib/owl/owl_builder.h"
#include "../owlib/parser/csv_log_parser.h"
#include "../owlib/reader/file_log_reader.h"

#include "http_log_parsed_data_holder.h"

namespace my {
    class MyHTTPLogMonitor {
    public:
        MyHTTPLogMonitor(const std::string &logFilePath,
                         int reportStatTimerSeconds,
                         int trafficCheckSeconds,
                         int trafficCheckThreshold);
        ~MyHTTPLogMonitor();

        void Start() {
            assert(m_httpLogOwl);
            m_httpLogOwl->Start();
        }

        void Stop() {
            assert(m_httpLogOwl);
            m_httpLogOwl->Stop();
        }

    private:
        moghya::LogOwl *m_httpLogOwl;
        std::unique_ptr<moghya::Owl> m_owlPtr;
    };
}// namespace my


#endif//LOGOWL_MY_HTTP_LOG_MONITOR_H
