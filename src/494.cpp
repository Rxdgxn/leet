#include "../include.h"

class Solution {
public:
    vector<vector<int>> memo;
    int totalSum = 0;

    int dfs(vector<int>& nums, int index, int curr, int& target) {
        if (index == nums.size()) {
            if (curr == target) return 1;
            else return 0;
        }
        else {
            if (memo[index][curr + totalSum] != INT_MIN)
                return memo[index][curr + totalSum];

            int add = dfs(nums, index + 1, curr + nums[index], target);
            int sub = dfs(nums, index + 1, curr - nums[index], target);

            return memo[index][curr + totalSum] = add + sub;
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        for (int n : nums)
            totalSum += n;

        memo = vector<vector<int>>(nums.size(), vector<int>(2 * totalSum + 1, INT_MIN));

        return dfs(nums, 0, 0, target);
    }
};