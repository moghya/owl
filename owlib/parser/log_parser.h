//
// Created by Shubham Sawant on 27/05/22.
//

#ifndef LOGOWL_LOG_PARSER_H
#define LOGOWL_LOG_PARSER_H

#include <cassert>
#include <map>
#include <vector>

#include "../utils.h"

namespace moghya {
    class ParsedLogDataHolder {
        public:
            virtual ~ParsedLogDataHolder() {}
            virtual void Initialize() = 0;
    };
    class LogParser {
        public:
            LogParser(ParsedLogDataHolder* parsedLogDataPtr):
                m_parsedLogDataPtr(parsedLogDataPtr) {
                assert(parsedLogDataPtr);
            }
            virtual ~LogParser() {
            }
            virtual ParsedLogDataHolder* ParseLogLine(const std::string& logLine) = 0;
        private:
            ParsedLogDataHolder* m_parsedLogDataPtr;
    };
}




#endif //LOGOWL_LOG_PARSER_H
