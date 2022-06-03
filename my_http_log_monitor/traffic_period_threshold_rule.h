//
// Created by Shubham Sawant on 29/05/22.
//

#ifndef LOGOWL_TRAFFIC_CHECK_RULE_H
#define LOGOWL_TRAFFIC_CHECK_RULE_H

#include <iostream>

#include "../owlib/rule/process_log_rule.h"
#include "http_log_parsed_data_holder.h"

namespace my {

    class TrafficPeriodThresholdRule : public moghya::ProcessLogRule {
        public:
            TrafficPeriodThresholdRule(int trafficPeriodSeconds,
                                       int trafficThresholdPerSeconds) :
                m_trafficPeriodSeconds(trafficPeriodSeconds),
                m_trafficThresholdPerSeconds(trafficThresholdPerSeconds),
                m_isThresholdHit(false),
                ProcessLogRule() {
            }
            ~TrafficPeriodThresholdRule() {
                m_requestTimesFreqMap.clear();
            }
            void Apply(moghya::ParsedLogDataHolder* parsedLogDataPtr) override;
        private:
            int m_trafficPeriodSeconds;
            int m_trafficThresholdPerSeconds;
            bool m_isThresholdHit;
            std::map<int,int> m_requestTimesFreqMap;
    };
}

#endif //LOGOWL_TRAFFIC_CHECK_RULE_H
