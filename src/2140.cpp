#include "../include.h"

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        const int n = questions.size();
        vector<long long> dp(n, -1);
        
        dp[n - 1] = questions[n - 1][0];

        for (int i = n - 2; i >= 0; i--) {
            int j = i + questions[i][1] + 1;
            long long k = questions[i][0];

            if (j < n)
                k += dp[j];

            dp[i] = max(k, dp[i + 1]);
        }
        
        return dp[0];
    }
};