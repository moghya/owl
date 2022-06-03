//
// Created by Shubham Sawant on 27/05/22.
//

#include <memory>

#include "owl_builder.h"

namespace moghya {
    std::unique_ptr<moghya::LogOwl>
    OwlBuilder::BuildLogOwl(LogOwlConfig &options) {
        return std::make_unique<moghya::LogOwl>(options);
    }
}// namespace moghya