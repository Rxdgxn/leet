#include "../include.h"

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        const int n = nums.size();
        int diff = -1;

        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (nums[j] - nums[i] > 0)
                    diff = max(diff, nums[j] - nums[i]);

        return diff;
    }
};