#include "../include.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;

        for (int num : nums) m[num]++;
        for (int num : nums)
            if (m[num] == 1) return num;

        return -1;
    }
};