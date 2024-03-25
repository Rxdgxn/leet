#include "../include.h"

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;

        for (int x : nums) {
            int idx = abs(x) - 1;

            if (nums[idx] < 0) ret.push_back(idx + 1);
            else nums[idx] *= -1;
        }

        return ret;
    }
};