//
// Created by Shubham Sawant on 27/05/22.
//

#include <iostream>

#include "../utils.h"
#include "csv_log_parser.h"

namespace moghya {
    ParsedLogDataHolder *CSVLogParser::ParseLogLine(const std::string &logLine) {
        std::vector<std::string> tempValues;
        moghya::SplitString(logLine, ",", tempValues);
        if (!m_headers.empty()) {
            m_parsedCSVLogDataPtr->Initialize(tempValues);
        }
        for (auto value : tempValues) {
            if (m_stripStringQuotes) {
                value = value.substr(1, value.size() - 2);
            }
            m_headers.push_back(value);
        }
        return m_parsedCSVLogDataPtr;
    }
}// namespace moghya