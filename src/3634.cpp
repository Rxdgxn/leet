#include "../include.h"

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long lk = k;

        int i = 0, j = 0;
        const int n = nums.size();

        int min = INT_MAX;

        while (i < n) {
            while (j < n && nums[j] <= lk * nums[i])
                j++;

            min = std::min(min, n - (j - i));
            
            i++;
        }

        return min;
    }
};