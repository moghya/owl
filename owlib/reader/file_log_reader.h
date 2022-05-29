//
// Created by Shubham Sawant on 29/05/22.
//

#ifndef LOGOWL_FILE_LOG_READER_H
#define LOGOWL_FILE_LOG_READER_H

#include <fstream>
#include <string>

#include "../exception/invalid_argument_exception.h"
#include "log_reader.h"

namespace moghya {
    class FileLogReader : public LogReader {
        public:
            FileLogReader(std::string logFilePath);
            ~FileLogReader();
            bool ReadLogLine(std::string& logLine) override;
        private:
            std::string m_logFilePath;
            std::ifstream m_logInputStream;
            uint32_t m_readLineCount = 0;
    };
}

#endif //LOGOWL_FILE_LOG_READER_H
