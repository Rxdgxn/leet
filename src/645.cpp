#include "../include.h"

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int freq[10001] = {0}, t = 0, s = 0;
        const int k = nums.size();

        for (int n : nums) {
            if (++freq[n] == 2) t = n;
            
            s += n;
        }

        return {t, t + (k * (k + 1)) / 2 - s};
    }
};