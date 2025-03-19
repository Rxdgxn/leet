#include "../include.h"

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (i + 2 >= n)
                    return -1;

                for (int j = i; j < i + 3; j++)
                    nums[j] = !nums[j];

                ops++;
            }
        }

        return ops;
    }
};