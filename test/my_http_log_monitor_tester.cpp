
#include <string>

#include "../my_http_log_monitor/my_http_log_monitor.h"

int main() {
    std::string logFilePath = "/Users/shubhamsawant/CLionProjects/logowl/test/http_log.csv";
    my::MyHTTPLogMonitor monitor(logFilePath,10,120,5);
    monitor.Start();
    monitor.Stop();
    return 0;
}
