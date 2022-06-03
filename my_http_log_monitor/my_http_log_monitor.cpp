//
// Created by Shubham Sawant on 28/05/22.
//

#include <cassert>
#include <memory>

#include "report_http_stats_rule.h"
#include "traffic_period_threshold_rule.h"

#include "my_http_log_monitor.h"

namespace my {
    MyHTTPLogMonitor::MyHTTPLogMonitor(const std::string &logFilePath,
                                       int reportStatTimerSeconds,
                                       int trafficPeriodSeconds,
                                       int trafficThresholdPerSeconds) {
        std::cout << "logFilePath: " << logFilePath << "\n";
        std::unique_ptr<moghya::LogParser> logParser = std::make_unique<moghya::CSVLogParser>(new my::HTTPLogParsedDataHolder(), true);
        std::unique_ptr<moghya::LogReader> logReader = std::make_unique<moghya::FileLogReader>(logFilePath);
        auto reportHTTPStatsRule = new my::ReportHTTPStatsRule(reportStatTimerSeconds);
        auto trafficPeriodThresholdRule = new my::TrafficPeriodThresholdRule(trafficPeriodSeconds,
                                                                             trafficThresholdPerSeconds);
        std::vector<moghya::ProcessLogRule *> rules{
                reportHTTPStatsRule,
                trafficPeriodThresholdRule};
        auto owlConfig = moghya::LogOwlConfig(std::move(logParser), std::move(logReader), rules, false);
        m_owlPtr = std::move(moghya::OwlBuilder::BuildLogOwl(owlConfig));
        assert(m_owlPtr);
        m_httpLogOwl = dynamic_cast<moghya::LogOwl *>(m_owlPtr.get());
        assert(m_httpLogOwl);
    }
    MyHTTPLogMonitor::~MyHTTPLogMonitor() {
    }
}// namespace my