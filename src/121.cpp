#include "../include.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();

        vector<int> dp(n);
        dp[n - 1] = prices[n - 1];

        for (int i = n - 2; i >= 0; i--)
            dp[i] = max(dp[i + 1], prices[i]);

        int ret = 0;

        for (int i = 0; i < n - 1; i++)
            ret = max(ret, dp[i + 1] - prices[i]);

        return ret;
    }
};