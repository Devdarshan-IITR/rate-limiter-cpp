#ifndef DEVDARSHAN_IITR_HPP
#define DEVDARSHAN_IITR_HPP

#include <string>
#include <deque>
#include <unordered_map>

namespace Devdarshan_IITR {

class RateLimiter {
public:
    bool isAllowed(const std::string& user_id,
                   long long timestamp,
                   int maxRequests,
                   int duration) {

        std::deque<long long>& timestamps = buckets_[user_id];

        while (!timestamps.empty()) {
            if (timestamps.front() < timestamp - duration) {
                timestamps.pop_front();
            } else {
                break;
            }
        }

        if ((int)timestamps.size() >= maxRequests) {
            return false;
        }

        timestamps.push_back(timestamp);
        return true;
    }

private:
    std::unordered_map<std::string, std::deque<long long>> buckets_;
};

} // namespace Devdarshan_IITR

#endif
