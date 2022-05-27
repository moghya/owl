//
// Created by Shubham Sawant on 27/05/22.
//

#ifndef LOGOWL_UTILS_H
#define LOGOWL_UTILS_H

#include <string>

namespace moghya {
    enum class OwlType {
        kLOG = 1,
    };

    enum class ServiceType {
        kHTTP = 0
    };

    enum class DataSourceType {
        kFILE = 0,
        kSTDIN = 1,
        kNETWORK = 2,
    };

    enum class DataSourceFormatType {
        kCSV = 0,
    };

    struct OwlConfig {
        OwlConfig(OwlType owlType,
                  ServiceType serviceType,
                  DataSourceType dataSourceType,
                  DataSourceFormatType dataSourceFormatType,
                  const std::string &dataSourceFilePath,
                  bool listenCommands);
        OwlType owlType;
        ServiceType serviceType;
        DataSourceType dataSourceType;
        DataSourceFormatType dataSourceFormatType;
        std::string dataSourceFilePath;
        bool listenCommands;
    };

}

#endif //LOGOWL_UTILS_H
