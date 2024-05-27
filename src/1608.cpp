#include "../include.h"

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int freq[1001] = {0}, x = 0;

        for (int n : nums) freq[n]++;

        for (int i = 1000; i >= 0; i--) {
            x += freq[i];
            if (x == i) return x;
        }

        return -1;
    }
};