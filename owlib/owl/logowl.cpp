//
// Created by Shubham Sawant on 27/05/22.
//

#include <iostream>

#include "../exception/invalid_argument_exception.h"
#include "../parser/csv_log_parser.h"
#include "../rule/process_log_rule.h"

#include "logowl.h"

namespace moghya {
    LogOwl::LogOwl(LogOwlConfig &config) : m_logParser(config.logParser.release()),
                                           m_logReader(config.logReader.release()),
                                           m_processLogRules(std::move(config.rules)),
                                           Owl(config) {
    }

    LogOwl::~LogOwl() {
        for (auto rule : m_processLogRules) {
            if (rule) delete rule;
        }
        m_processLogRules.clear();
    }

    bool LogOwl::Observe() {
        std::string logLine;
        while (m_logReader->ReadLogLine(logLine)) {
            if (!ProcessLogLine(logLine)) {
                std::cout << "Could not process: " << logLine;
            }
        }
        return true;
    }

    std::string LogOwl::Info() {
        return "LogOwl::";
    }

    bool LogOwl::ProcessLogLine(const std::string &logLine) {
        auto parsedDataPtr = m_logParser->ParseLogLine(logLine);
        if (!parsedDataPtr) {
            return false;
        }
        for (auto rule : m_processLogRules) {
            rule->Apply(parsedDataPtr);
        }
        return true;
    }
}// namespace moghya