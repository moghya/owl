//
// Created by Shubham Sawant on 27/05/22.
//

#ifndef LOGOWL_PROCESS_LOG_RULE_H
#define LOGOWL_PROCESS_LOG_RULE_H

#include "../parser/csv_log_parser.h"
#include "../parser/log_parser.h"

namespace moghya {
    class ProcessLogRule {
    public:
        ProcessLogRule() {}
        virtual ~ProcessLogRule() {}

        [[maybe_unused]] virtual void Apply(moghya::ParsedLogDataHolder *parsedLogDataPtr) {}
    };

}// namespace moghya

#endif//LOGOWL_PROCESS_LOG_RULE_H
