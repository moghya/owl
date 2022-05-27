//
// Created by Shubham Sawant on 27/05/22.
//

#ifndef LOGOWL_LOGOWL_H
#define LOGOWL_LOGOWL_H

#include<fstream>
#include<string>

#include "owl.h"
#include "utils.h"


namespace moghya {
    class LogOwl : public Owl {
    protected:
        LogOwl(const OwlConfig& config);
        virtual ~LogOwl();
    protected:
        bool Observe() override;
        virtual bool ReadLogLine(std::string& logLine) = 0;
        virtual bool ProcessLogLine(const std::string& logLine) = 0;

    private:
        moghya::DataSourceFormatType logFormatType;
        moghya::DataSourceType logSourceType;
        std::string logFilePath;
        std::ifstream logInputStream;
    };
}


#endif //LOGOWL_LOGOWL_H
