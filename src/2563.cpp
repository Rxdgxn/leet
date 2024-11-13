#include "../include.h"

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ret = 0;

        for (int i = 0; i < nums.size(); i++) {
            int l = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int u = lower_bound(nums.begin() + i + 1, nums.end(), upper - nums[i] + 1) - nums.begin();

            ret += static_cast<long long>(u - l);
        }

        return ret;
    }
};