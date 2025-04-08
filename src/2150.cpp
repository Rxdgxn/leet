#include "../include.h"

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        if (nums.size() < 2)
            return nums;

        sort(nums.begin(), nums.end());
        vector<int> ret;

        const int n = nums.size();

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] - nums[i - 1] >= 2 && nums[i + 1] - nums[i] >= 2) {
                ret.push_back(nums[i]);
            }
        }

        if (nums[1] - nums[0] >= 2) ret.push_back(nums[0]);
        if (nums[n - 1] - nums[n - 2] >= 2) ret.push_back(nums[n - 1]);

        return ret;
    }
};