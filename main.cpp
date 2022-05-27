#include <iostream>
#include "logowl_lib/utils.h"
#include "logowl_lib/logowl.h"

int main(int argc, char** argv) {
    if(argc!=2) {
        throw "Invalid args to logowl, pass filepath to read from";
    }
    moghya::LogOwlOptions options(
        moghya::LogOwlType::kHTTP,
        moghya::LogSourceType::kFILE,
        moghya::LogFormatType::kCSV,
        std::string(argv[1])
    );
    auto http_log_owl = std::make_unique<moghya::LogOwl>(options);
    http_log_owl->Start();
    http_log_owl->Stop();
    return 0;
}
