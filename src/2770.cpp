#include "../include.h"

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        const int n = nums.size();
        vector<int> dp(n, -1); // dp[i] max jumps till i from 0

        dp[0] = 0;

        for (int j = 1; j < n; j++)
            for (int i = 0; i < j; i++)
                if (abs(nums[i] - nums[j]) <= target && dp[i] != -1)
                    dp[j] = max(dp[j], dp[i] + 1);
        
        return dp[n - 1];
    }
};