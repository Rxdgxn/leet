#include "../include.h"

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        const int n = nums.size();
        int st = 0, dr = 0, ret = 0, p = 1;

        if (k <= 1) return 0;

        while (dr < n) {
            p *= nums[dr];
            while (p >= k) p /= nums[st++];

            ret += (dr - st + 1);

            dr++;
        }

        return ret;
    }
};