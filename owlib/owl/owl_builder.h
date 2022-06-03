//
// Created by Shubham Sawant on 27/05/22.
//

#ifndef LOGOWL_OWL_BUILDER_H
#define LOGOWL_OWL_BUILDER_H

#include <memory>

#include "../parser/log_parser.h"
#include "../rule/process_log_rule.h"
#include "../utils.h"
#include "logowl.h"

namespace moghya {
    class OwlBuilder {
    public:
        static std::unique_ptr<moghya::LogOwl> BuildLogOwl(moghya::LogOwlConfig &options);
        OwlBuilder() = delete;
        ~OwlBuilder() = delete;
    };
}// namespace moghya

#endif//LOGOWL_OWL_BUILDER_H
