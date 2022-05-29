//
// Created by Shubham Sawant on 27/05/22.
//

#include "invalid_argument_exception.h"

namespace moghya {
    InvalidArgumentException::InvalidArgumentException(const std::string msg)
            : runtime_error(msg) {

    }
    InvalidArgumentException::~InvalidArgumentException() {

    }
}


