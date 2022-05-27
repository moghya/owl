//
// Created by Shubham Sawant on 27/05/22.
//

#ifndef LOGOWL_HTTP_LOGOWL_H
#define LOGOWL_HTTP_LOGOWL_H

#include "logowl.h"

namespace moghya {
    class HTTPLogOwl : public LogOwl {
        public:
            HTTPLogOwl(const OwlConfig& options) :
                LogOwl(options) {
            }
            ~HTTPLogOwl() {}

        protected:
            bool ReadLogLine(std::string& logLine) override {
                return true;
            }

            bool ProcessLogLine(const std::string& logLine) override {
                return true;
            }

            std::string OwlInfo() override {
                return "HTTPLogOwl::";
            }

            bool GenerateAlert(Alert& alert) override {
                return true;
            }
    };
}

#endif //LOGOWL_HTTP_LOGOWL_H
