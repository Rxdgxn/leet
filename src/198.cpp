#include "../include.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        vector<int> r(n + 1, 0);

        r[1] = nums[0];
        for (int i = 1; i < n; i++)
            r[i + 1] = max(r[i - 1] + nums[i], r[i]);

        return r[n];
    }
};