#include "../include.h"

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int s = 0;

        for (int bit = 0; bit <= 31; bit++) {
            int cnt = 0;
            for (int num : nums) {
                if (((1 << bit) & num) == (1 << bit)) cnt++;
            }
            
            if (cnt >= k) s += (1 << bit);
        }

        return s;
    }
};