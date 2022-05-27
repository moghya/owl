//
// Created by Shubham Sawant on 27/05/22.
//

#include "invalid_argument_exception.h"
#include "owl_builder.h"
#include "utils.h"
#include "http_logowl.h"

namespace moghya {
    std::unique_ptr<moghya::Owl> OwlBuilder::Build(const OwlConfig& options) {
        switch(options.serviceType) {
            case moghya::ServiceType::kHTTP: {
                if (options.owlType == moghya::OwlType::kLOG) {
                    return std::make_unique<moghya::HTTPLogOwl>(options);
                }
                break;
            }
        }
        throw InvalidArgumentException("Could not build Owl");
        return nullptr;
    }
}