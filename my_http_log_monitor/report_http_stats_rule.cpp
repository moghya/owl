//
// Created by Shubham Sawant on 29/05/22.
//

#include <cassert>

#include "report_http_stats_rule.h"

namespace my {
    void ReportHTTPStatsRule::Apply(moghya::ParsedLogDataHolder *parsedLogDataPtr) {
        my::HTTPLogParsedDataHolder *httpLogParsedDataPtr = dynamic_cast<my::HTTPLogParsedDataHolder *>(parsedLogDataPtr);
        assert(httpLogParsedDataPtr);
        CollectStats(httpLogParsedDataPtr);
        MaybeReportStats(httpLogParsedDataPtr);
    }

    void ReportHTTPStatsRule::CollectStats(my::HTTPLogParsedDataHolder *httpLogParsedDataPtr) {
        auto remote = httpLogParsedDataPtr->remote;
        m_remoteHitCountMap[remote]++;
        remoteSiteSectionSetMap[remote].insert(httpLogParsedDataPtr->section);
    }

    void ReportHTTPStatsRule::MaybeReportStats(my::HTTPLogParsedDataHolder *httpLogParsedDataPtr) {
        int currentLogTime = httpLogParsedDataPtr->date;
        m_currentTime = std::max(m_currentTime, currentLogTime);
        if (lastStatReportTime == 0) {
            lastStatReportTime = m_currentTime;
        }
        if ((m_currentTime - lastStatReportTime) >= reportStatTimerSeconds) {
            std::cout << "HTTPStats at " << currentLogTime << "\n";
            auto mostHitRemoteItr = std::max_element(
                    m_remoteHitCountMap.begin(), m_remoteHitCountMap.end(),
                    [](const std::pair<std::string, uint32_t> &a,
                       const std::pair<std::string, uint32_t> &b) -> bool {
                        return a.second < b.second;
                    });
            std::cout << "\tMost Hit Remote: " << mostHitRemoteItr->first << "\n";
            std::cout << "\tRemote Hit Count: " << mostHitRemoteItr->second << "\n";
            std::cout << "\tSections of Remote: " << mostHitRemoteItr->first << "\n";
            for (auto &section : remoteSiteSectionSetMap[mostHitRemoteItr->first]) {
                std::cout << "\t\t" << section << "\n";
            }
            std::cout << "____________________________________________________\n";
            lastStatReportTime = m_currentTime;
            m_remoteHitCountMap.clear();
            remoteSiteSectionSetMap.clear();
        }
    }
}// namespace my