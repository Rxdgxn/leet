#include "../include.h"

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        const int n = nums.size();
        int valid = 0;

        vector<long long> dp(n + 1, 0);

        for (int i = 0; i < n; i++)
            dp[i + 1] = dp[i] + nums[i];

        for (int i = 0; i < n - 1; i++)
            if (dp[i + 1] >= dp[n] - dp[i + 1])
                valid++;

        return valid;
    }
};