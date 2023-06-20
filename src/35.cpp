#include "../include.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int p = (l + r) / 2;
            if (nums[p] < target) l = p + 1;
            else if (nums[p] > target) r = p - 1;
            else return p;
        }
        return l + (nums[l] < target);
    }
};