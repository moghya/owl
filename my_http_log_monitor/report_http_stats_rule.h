//
// Created by Shubham Sawant on 29/05/22.
//

#ifndef LOGOWL_REPORT_HTTP_STATS_RULE_H
#define LOGOWL_REPORT_HTTP_STATS_RULE_H

#include <iostream>
#include <map>
#include <set>

#include "../owlib/rule/process_log_rule.h"
#include "http_log_parsed_data_holder.h"

namespace my {
    class ReportHTTPStatsRule : public moghya::ProcessLogRule {
        public:
            ReportHTTPStatsRule(uint32_t reportStatTimerSeconds) :
                reportStatTimerSeconds(reportStatTimerSeconds),
                ProcessLogRule() {
            }
            ~ReportHTTPStatsRule() {
                m_remoteHitCountMap.clear();
                remoteSiteSectionSetMap.clear();
            }
            void Apply(moghya::ParsedLogDataHolder* parsedLogDataPtr) override;

        private:
            void CollectStats(my::HTTPLogParsedDataHolder* httpLogParsedDataPtr);
            void MaybeReportStats(my::HTTPLogParsedDataHolder* httpLogParsedDataPtr);

        private:
            uint32_t reportStatTimerSeconds;
            uint32_t lastStatReportTime = 0;
            int m_currentTime = 0;
            std::map<std::string,uint32_t> m_remoteHitCountMap;
            std::map<std::string,std::set<std::string>> remoteSiteSectionSetMap;
    };
}

#endif //LOGOWL_REPORT_HTTP_STATS_RULE_H
