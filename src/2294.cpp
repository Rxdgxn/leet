#include "../include.h"

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int parts = 1, m = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - m > k) {
                m = nums[i];
                parts++;
            }
        }

        return parts;
    }
};