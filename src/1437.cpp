#include "../include.h"

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int p = -1;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i]) {
                if (p < 0) p = i;
                else {
                    if (i - p - 1 < k) return false;
                    p = i;
                }
            }

        return true;
    }
};