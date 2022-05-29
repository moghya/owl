//
// Created by Shubham Sawant on 27/05/22.
//

#ifndef LOGOWL_UTILS_H
#define LOGOWL_UTILS_H

#include <string>
#include <vector>

namespace moghya {
    static void SplitString(std::string str,
                            std::string delimeter,
                            std::vector<std::string>& result ) {
        result.clear();
        size_t pos = 0;
        while ((pos = str.find(delimeter)) != std::string::npos) {
            std::string token = str.substr(0, pos);
            if (token.length() > 0) result.push_back(token);
            str.erase(0, pos + delimeter.length());
        }
        if (str.length() > 0) result.push_back(str);
    }
}

#endif //LOGOWL_UTILS_H
