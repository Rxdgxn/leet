#include "../include.h"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum % 2) return false;

        sum /= 2;

        vector<int> dp(sum + 1, false);
        dp[0] = true;

        for (int i = 0; i < n; i++) {
            for (int s = sum; s >= nums[i]; s--) {
                dp[s] = dp[s] || dp [s - nums[i]];
                
                if (dp[sum]) return true;
            }
        }

        return false;
    }
};