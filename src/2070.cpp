#include "../include.h"

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Maybe a bit overkill, could've just modified items
        map<int, int> dp;
        sort(items.begin(), items.end());

        dp[items[0][0]] = items[0][1];

        int prev_key = items[0][0];

        for (int i = 1; i < items.size(); i++) {
            dp[items[i][0]] = max(dp[prev_key], items[i][1]);
            prev_key = items[i][0];
        }

        vector<int> keys, ret;

        for (auto& [k, _] : dp)
            keys.push_back(k);

        const int ksz = keys.size();

        for (int q : queries) {
            int st = 0, dr = ksz - 1, mx = 0;

            while (st <= dr) {
                int p = (st + dr) / 2;

                if (keys[p] > q) dr = p - 1;
                else {
                    mx = max(mx, dp[keys[p]]);
                    st = p + 1;
                }
            }

            ret.push_back(mx);
        }

        return ret;
    }
};