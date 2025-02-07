#include "../include.h"

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        const int n = nums.size();

        set<int> s;
        int m = INT_MAX;

        for (int i = x; i < nums.size(); i++) {
            s.insert(nums[i - x]);

            auto z = s.upper_bound(nums[i]);
            
            if (z != s.end()) m = min(m, abs(*z - nums[i]));
            if (z != s.begin()) m = min(m, abs(*(--z) - nums[i]));
        }

        return m;
    }
};