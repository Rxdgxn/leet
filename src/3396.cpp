#include "../include.h"

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        const int n = nums.size();

        int set[101] = {0};

        for (int i = n - 1; i >= 0; i--) {
            if (set[nums[i]])
                return ceil(static_cast<float>(i + 1) / 3);

            set[nums[i]] = 1;
        }

        return 0;
    }
};