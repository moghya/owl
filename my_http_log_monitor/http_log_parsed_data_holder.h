//
// Created by Shubham Sawant on 29/05/22.
//

#ifndef LOGOWL_HTTP_LOG_PARSED_DATA_HOLDER_H
#define LOGOWL_HTTP_LOG_PARSED_DATA_HOLDER_H

#include "../owlib/parser/csv_log_parser.h"

namespace my {
    class HTTPLogParsedDataHolder : public moghya::CSVLogParsedDataHolder {
    public:
        void Initialize(std::vector<std::string> &values) override;
        HTTPLogParsedDataHolder() {
        }
        ~HTTPLogParsedDataHolder() {
        }

    private:
        void ParseRequest();

    public:
        std::string remote;
        std::string rfc931;
        std::string authUser;
        uint32_t date;
        std::string request;
        uint32_t status;
        uint32_t bytes;

        std::string method;
        std::string uri;
        std::string section;
        std::string protocol;
    };
}// namespace my


#endif//LOGOWL_HTTP_LOG_PARSED_DATA_HOLDER_H
