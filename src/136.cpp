#include "../include.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int occ[60001] = {0};

        for (int num : nums) occ[30000 + num]++;
        for (int num : nums)
            if (occ[30000 + num] == 1) return num;

        return -1;
    }
};