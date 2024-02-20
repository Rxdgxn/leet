#include "../include.h"

class Solution {
public:
    int missingNumber(const vector<int>& nums) {
        int s = 0, l = 1;

        for (const int& n : nums) {
            s += n;
            ++l;
        }

        return l * (l - 1) / 2 - s;
    }
};