//
// Created by Shubham Sawant on 27/05/22.
//

#ifndef LOGOWL_LOGOWL_H
#define LOGOWL_LOGOWL_H

#include<fstream>
#include<string>

#include "../utils.h"
#include "../parser/log_parser.h"
#include "../reader/log_reader.h"
#include "../rule/process_log_rule.h"

#include "owl.h"

namespace moghya {
    class LogOwlConfig : public OwlConfig {
        public:
            LogOwlConfig(std::unique_ptr<LogParser> logParser,
                         std::unique_ptr<LogReader> logReader,
                         std::vector<ProcessLogRule*> rules,
                         bool listenCommands) :
                logParser(std::move(logParser)),
                logReader(std::move(logReader)),
                rules(rules),
                OwlConfig(listenCommands) {
            }
            std::unique_ptr<LogParser> logParser;
            std::unique_ptr<LogReader> logReader;
            std::vector<ProcessLogRule*> rules;
    };

    class LogOwl : public Owl {
        public:

        LogOwl(moghya::LogOwlConfig& config);
        ~LogOwl();

        protected:
            virtual bool Observe() override;
            virtual std::string Info() override;
            virtual bool ProcessLogLine(const std::string& logLine);
        protected:
            std::unique_ptr<LogParser> m_logParser;
            std::unique_ptr<LogReader> m_logReader;
            std::vector<ProcessLogRule*> m_processLogRules;
    };
}


#endif //LOGOWL_LOGOWL_H
