//
// Created by Shubham Sawant on 27/05/22.
//

#include <iostream>
#include "logowl.h"
#include "invalid_argument_exception.h"

namespace moghya {

    LogOwl::LogOwl(const OwlConfig& config) :
            logSourceType(config.dataSourceType),
            logFormatType(config.dataSourceFormatType),
            logFilePath(config.dataSourceFilePath),
            Owl(config) {
        switch(logSourceType) {
            case moghya::DataSourceType::kFILE: {
                if (logFilePath.empty()) {
                    throw InvalidArgumentException("LogFilePath not specified.");
                }
                logInputStream.open(logFilePath, std::ifstream::in);
                break;
            }
            default:
                throw InvalidArgumentException("Unsupported LogSourceType not specified.");
        }
    }

    LogOwl::~LogOwl() {

    }
    bool LogOwl::Observe() {
        std::string logLine;
        while(ReadLogLine(logLine)) {
            ProcessLogLine(logLine);
        }
        return true;
    }

}