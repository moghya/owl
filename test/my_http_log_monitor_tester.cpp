
#include <string>

#include "../my_http_log_monitor/my_http_log_monitor.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Run with logFilePath as command line arg.";
        return -1;
    }
    std::string logFilePath(argv[1]);
    const int reportStatTimerSeconds = 10;
    const int trafficCheckSeconds = 120;
    const int trafficCheckThreshold = 5;
    my::MyHTTPLogMonitor monitor(logFilePath,
                                 reportStatTimerSeconds,
                                 trafficCheckSeconds,
                                 trafficCheckThreshold);
    monitor.Start();
    monitor.Stop();
    return 0;
}
