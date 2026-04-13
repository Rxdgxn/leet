#include "../include.h"

class Solution {
public:
    // Or 2 pointers
    int getMinDistance(vector<int>& nums, int target, int start) {
        const int n = nums.size();
        int ret = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (i - start > ret)
                break;

            const int diff = abs(i - start);

            if (nums[i] == target)
                ret = diff;
        }

        return ret;
    }
};