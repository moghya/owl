//
// Created by Shubham Sawant on 29/05/22.
//

#include "http_log_parsed_data_holder.h"

namespace my {

    void HTTPLogParsedDataHolder::Initialize(std::vector<std::string>& values) {
        int idx = 0;
        remote = values[idx++];
        rfc931 = values[idx++];
        authUser = values[idx++];
        date = std::stoi(values[idx++]);
        request = values[idx++];
        status = std::stoi(values[idx++]);
        bytes = std::stoi(values[idx++]);
        ParseRequest();
    }

    void HTTPLogParsedDataHolder::ParseRequest() {
        std::vector<std::string> requestParts;
        moghya::SplitString(request, " ", requestParts);
        assert(requestParts.size() == 3);
        method = requestParts[0];
        uri = requestParts[1];
        protocol = requestParts[3];

        std::vector<std::string> uriParts;
        moghya::SplitString(uri, "/", uriParts);
        section = uriParts[0];
    }
}