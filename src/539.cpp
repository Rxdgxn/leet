#include "../include.h"

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        map<int, int> mp;

        for (auto& t : timePoints) {
            int h = (t[0] - '0') * 10 + (t[1] - '0');
            int m = (t[3] - '0') * 10 + (t[4] - '0');
            int time = h * 60 + m;

            mp[time]++;
            mp[-(24 * 60 - time)]++;
        }

        int counted = 0, prev, m = INT_MAX;

        for (auto& [k, v] : mp) {
            if (v > 1) return 0;

            if (counted && k != 24 * 60 - prev) {
                m = min(m, abs(k - prev));
            }
            else {
                counted = 1;
            }

            prev = k;
        }

        return m;
    }
};