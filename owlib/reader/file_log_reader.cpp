//
// Created by Shubham Sawant on 29/05/22.
//

#include <cassert>

#include "file_log_reader.h"

namespace moghya {
    FileLogReader::FileLogReader(std::string logFilePath) :
        m_logFilePath(logFilePath),
        LogReader() {
        if (m_logFilePath.empty()) {
            throw InvalidArgumentException("LogFilePath not specified.");
        }
        m_logInputStream.open(m_logFilePath, std::ifstream::in);
        assert(m_logInputStream.is_open());
    }

    FileLogReader::~FileLogReader() {
        if (m_logInputStream.is_open()) {
            m_logInputStream.close();
        }
    }

    bool FileLogReader::ReadLogLine(std::string& logLine) {
        assert(m_logInputStream.is_open());
        try {
            std::getline(m_logInputStream, logLine);
            if (logLine.empty()) return false;
            m_readLineCount++;
        } catch (std::ios_base::failure failure) {
            return false;
        }
        return true;
    }
}