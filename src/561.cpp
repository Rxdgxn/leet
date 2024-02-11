#include "../include.h"

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int s = 0, sz = nums.size();

        for (int i = 0; i < sz; i += 2)
            s += min(nums[i], nums[i + 1]);

        return s;
    }
};