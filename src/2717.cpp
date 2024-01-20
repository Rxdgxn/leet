#include "../include.h"

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int x1 = 1, xn = nums.size(), p1, pn;

        for (int i = 0; i < xn; i++) {
            if (nums[i] == x1) p1 = i + 1;
            else if (nums[i] == xn) pn = i + 1;
        }

        return (p1 - x1) + (xn - pn) - (p1 > pn);
    }
};