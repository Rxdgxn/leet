#include "../include.h"

class Solution {
public:
    int helper(const vector<int>& nums, int goal) {
        int st = 0, dr = 0, n = nums.size(), x = 0, t = 0;

        while (dr < n) {
            x += nums[dr];

            while (st <= dr && x > goal) {
                x -= nums[st++];
            }

            t += dr - st + 1;

            dr++;
        }

        return t;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal - 1);
    }
};