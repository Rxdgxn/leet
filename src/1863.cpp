#include "../include.h"

class Solution {
public:
    void back(int set_xor, int i, vector<int>& nums, int& sum) {
        if (i >= nums.size()) {
            sum += set_xor;
            return;
        }

        back(set_xor, i + 1, nums, sum);
        back(set_xor ^ nums[i], i + 1, nums, sum);
    }

    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        back(0, 0, nums, sum);

        return sum;
    }
};