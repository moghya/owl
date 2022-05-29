//
// Created by Shubham Sawant on 29/05/22.
//

#include <map>
#include <numeric>
#include "traffic_period_threshold_rule.h"


namespace my {
    void TrafficPeriodThresholdRule::Apply(moghya::ParsedLogDataHolder* parsedLogDataPtr)  {
        my::HTTPLogParsedDataHolder* httpLogParsedDataPtr = dynamic_cast<my::HTTPLogParsedDataHolder*>(parsedLogDataPtr);
        assert(httpLogParsedDataPtr);
        int currentLogTime = httpLogParsedDataPtr->date;
        m_requestTimesFreqMap[currentLogTime]++;
        auto maxTimestamp = m_requestTimesFreqMap.rbegin()->first;
        auto minTimestamp = m_requestTimesFreqMap.begin()->first;
        if ((maxTimestamp - minTimestamp) < m_trafficPeriodSeconds) {
            return;
        }
        auto lowerLimitTime = (maxTimestamp - m_trafficPeriodSeconds);
        std::erase_if(m_requestTimesFreqMap,
                       [lowerLimitTime](const auto& entry) { return entry.first < lowerLimitTime;});
        int totalRequests = std::accumulate(std::begin(m_requestTimesFreqMap),
                        std::end(m_requestTimesFreqMap),
                        0,
                        [] (int value, const std::map<int, int>::value_type& temp) {
                            return value + temp.second;});
        int avgRequestsPerSecond = totalRequests/m_requestTimesFreqMap.size();
        if (!m_isThresholdHit && avgRequestsPerSecond >= m_trafficThresholdPerSeconds) {
            m_isThresholdHit = true;
            std::cout << "Traffic Period Threshold Hit" << "\n";
            std::cout << "\t Hit Time= " << maxTimestamp << "\n";
            std::cout << "\t Average Traffic= " << avgRequestsPerSecond << "\n";
            std::cout << "_______________________________________\n";
        }
        if (m_isThresholdHit && avgRequestsPerSecond < m_trafficThresholdPerSeconds) {
            m_isThresholdHit = false;
            std::cout << "Traffic Period Threshold Recovered" << "\n";
            std::cout << "\t Recovery Time= " << maxTimestamp << "\n";
            std::cout << "\t Average Traffic= " << avgRequestsPerSecond << "\n";
            std::cout << "_______________________________________\n";
        }
    }
}