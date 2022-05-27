//
// Created by Shubham Sawant on 27/05/22.
//

#include "utils.h"

namespace moghya {
    OwlConfig::OwlConfig(OwlType owlType, ServiceType serviceType, DataSourceType dataSourceType,
                         DataSourceFormatType dataSourceFormatType, const std::string &dataSourceFilePath,
                         bool listenCommands) : owlType(owlType), serviceType(serviceType),
                                                dataSourceType(dataSourceType),
                                                dataSourceFormatType(dataSourceFormatType),
                                                dataSourceFilePath(dataSourceFilePath),
                                                listenCommands(listenCommands) {}
}