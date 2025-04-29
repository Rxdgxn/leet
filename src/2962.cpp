#include "../include.h"

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        vector<int> indices;
        int max = *max_element(nums.begin(), nums.end());
        int j = 0, curr = 0;

        long long count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == max)
                curr++;

            while (curr == k) {
                if (nums[j] == max)
                    curr--;
                j++;
            }

            count += j;
        }

        return count;
    }
};