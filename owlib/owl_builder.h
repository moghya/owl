//
// Created by Shubham Sawant on 27/05/22.
//

#ifndef LOGOWL_OWL_BUILDER_H
#define LOGOWL_OWL_BUILDER_H


#include "owl.h"
#include "utils.h"

namespace moghya {
    class OwlBuilder {
    public:
        static std::unique_ptr<moghya::Owl> Build(const OwlConfig& options);
        OwlBuilder() = delete;
        ~OwlBuilder() = delete;
    };
}

#endif //LOGOWL_OWL_BUILDER_H
