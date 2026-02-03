#include "../include.h"

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        const int n = nums.size();
        
        int i = 0;

        while (i < n - 1 && nums[i] < nums[i + 1])
            i++;

        int p = i;

        while (i < n - 1 && nums[i] > nums[i + 1])
            i++;

        int q = i;

        while (i < n - 1 && nums[i] < nums[i + 1])
            i++;

        return 0 < p && p < q && q < n - 1 && i == n - 1;
    }
};