#include <iostream>

#include "../http_logowl.h"
#include "../owl_builder.h"

int main() {
    std::string logFilePath = "/Users/shubhamsawant/CLionProjects/logowl/owlib/test/http_log.csv";
    moghya::OwlConfig config(
            moghya::OwlType::kLOG,
            moghya::ServiceType::kHTTP,
            moghya::DataSourceType::kFILE,
            moghya::DataSourceFormatType::kCSV,
            std::string(logFilePath),
            false
    );
    auto http_log_owl = moghya::OwlBuilder::Build(config);
    http_log_owl->Start();
    http_log_owl->Stop();
    return 0;
}
