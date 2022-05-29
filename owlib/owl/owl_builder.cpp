//
// Created by Shubham Sawant on 27/05/22.
//

#include "../exception/invalid_argument_exception.h"
#include "owl_builder.h"

namespace moghya {
    std::unique_ptr<moghya::LogOwl>
    OwlBuilder::BuildLogOwl(LogOwlConfig& options) {
        return std::make_unique<moghya::LogOwl>(options);
    }
}