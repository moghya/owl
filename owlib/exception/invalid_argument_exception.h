//
// Created by Shubham Sawant on 27/05/22.
//

#ifndef LOGOWL_INVALID_ARGUMENT_EXCEPTION_H
#define LOGOWL_INVALID_ARGUMENT_EXCEPTION_H

#include<stdexcept>
#include<string>

namespace moghya {
    class InvalidArgumentException : public std::runtime_error {
    public:
        InvalidArgumentException(const std::string msg);

        ~InvalidArgumentException();
    };

}

#endif //LOGOWL_INVALID_ARGUMENT_EXCEPTION_H
