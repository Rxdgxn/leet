#include "../include.h"

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());

        int req = 0;
        const int n = ages.size();

        auto it = ages.begin();

        while (it != ages.end()) {
            auto lb = lower_bound(ages.begin(), it, *it / 2 + 8);
            auto ub = upper_bound(it, ages.end(), *it);

            if (*it <= 14) {
                it = ub;
                continue;
            }

            int eq = ub - it;

            req += eq * (eq - 1); // in between same age group
            req += eq * (it - lb); // each to every (valid) person below

            it = ub;
        }

        return req;
    }
};