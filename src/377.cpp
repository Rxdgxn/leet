#include "../include.h"

class Solution {
public:
    vector<int> dp;
    int n;

    int back(vector<int>& nums, int target) {
        if (target == 0) return 1;
        if (target < 0) return 0;

        int sum = 0;

        if (dp[target] != -1) return dp[target];

        for (int i = 0; i < n; i++)
            if (nums[i] <= target)
                sum += back(nums, target - nums[i]);

        return dp[target] = sum;
    }

    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        dp = vector<int>(target + 1, -1);

        return back(nums, target);
    }
};