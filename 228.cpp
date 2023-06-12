#include "include.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int sz = nums.size();

        for (int i = 0; i < sz; i++) {
            int s = nums[i];
            while (i + 1 < sz && nums[i] + 1 == nums[i + 1]) i++;

            if (s != nums[i])
                ret.push_back(to_string(s) + "->" + to_string(nums[i]));
            else
                ret.push_back(to_string(s));
            s = nums[i+1];
        }

        return ret;
    }
};