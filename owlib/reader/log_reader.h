//
// Created by Shubham Sawant on 28/05/22.
//

#ifndef LOGOWL_LOG_READER_H
#define LOGOWL_LOG_READER_H

#include <string>

namespace moghya {
    class LogReader {
        public:
            LogReader() {}
            virtual ~LogReader() {}
            virtual bool ReadLogLine(std::string& line) = 0;
    };
}

#endif //LOGOWL_LOG_READER_H
