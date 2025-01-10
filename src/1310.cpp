#include "../include.h"

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        const int n = arr.size();

        vector<int> dp(n);
        dp[0] = arr[0];

        for (int i = 1; i < n; i++)
            dp[i] = dp[i - 1] ^ arr[i];

        vector<int> ret;
        for (auto& q : queries) {
            if (q[0] - 1 >= 0) ret.push_back(dp[q[1]] ^ dp[q[0] - 1]);
            else ret.push_back(dp[q[1]]);
        }

        return ret;
    }
};