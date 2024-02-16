#include "../include.h"

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        long long p = -1, x = 0;
        const int sz = nums.size();

        for (int i = 0; i < sz; i++) {
            if (nums[i] < x) p = x + nums[i];
            x += nums[i];
        }

        return p;
    }
};