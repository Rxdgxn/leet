#include "../include.h"

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie();

        sort(nums.begin(), nums.end());

        int st = 0, dr = nums.size() - 1;

        while (st < dr && nums[st] < 0) {
            if (-nums[st] == nums[dr]) return nums[dr];

            if (nums[dr] > -nums[st]) dr--;
            if (-nums[st] > nums[dr]) st++;
        }

        return -1;
    }
};