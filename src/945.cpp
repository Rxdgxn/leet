#include "../include.h"

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ret = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                int x = nums[i - 1] + 1 - nums[i];
                ret += x;

                nums[i] = nums[i - 1] + 1;
            }
        }

        return ret;
    }
};