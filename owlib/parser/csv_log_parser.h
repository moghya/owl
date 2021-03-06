//
// Created by Shubham Sawant on 27/05/22.
//

#ifndef LOGOWL_CSV_LOG_PARSER_H
#define LOGOWL_CSV_LOG_PARSER_H

#include <cassert>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "log_parser.h"

namespace moghya {

    class CSVLogParsedDataHolder : public ParsedLogDataHolder {
    public:
        ~CSVLogParsedDataHolder() {}
        void Initialize() override {
        }
        virtual void Initialize(std::vector<std::string> &values) = 0;
    };

    class CSVLogParser : public LogParser {
    public:
        CSVLogParser(CSVLogParsedDataHolder *parsedCSVLogDataPtr,
                     bool stripStringQuotes = false) : m_parsedCSVLogDataPtr(parsedCSVLogDataPtr),
                                                       m_stripStringQuotes(stripStringQuotes),
                                                       LogParser(parsedCSVLogDataPtr) {
            assert(m_parsedCSVLogDataPtr);
        }
        ~CSVLogParser() {
            if (m_parsedCSVLogDataPtr) delete m_parsedCSVLogDataPtr;
        }

        ParsedLogDataHolder *ParseLogLine(const std::string &logLine) override;

        const std::vector<std::string> &Headers() const {
            return m_headers;
        }

        const CSVLogParsedDataHolder &CurrentLineValueMap() const {
            return *m_parsedCSVLogDataPtr;
        }

    protected:
        CSVLogParsedDataHolder *m_parsedCSVLogDataPtr;
        bool m_stripStringQuotes;
        std::vector<std::string> m_headers;
    };
}// namespace moghya

#endif//LOGOWL_CSV_LOG_PARSER_H
