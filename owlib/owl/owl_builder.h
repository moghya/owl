//
// Created by Shubham Sawant on 27/05/22.
//

#ifndef LOGOWL_OWL_BUILDER_H
#define LOGOWL_OWL_BUILDER_H

#include "logowl.h"
#include "../utils.h"
#include "../parser/log_parser.h"
#include "../rule/process_log_rule.h"

namespace moghya {
    class OwlBuilder {
        public:
            static std::unique_ptr<moghya::LogOwl> BuildLogOwl(moghya::LogOwlConfig& options);
            OwlBuilder() = delete;
            ~OwlBuilder() = delete;
    };
}

#endif //LOGOWL_OWL_BUILDER_H
