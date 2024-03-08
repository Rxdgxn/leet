#include "../include.h"

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101] = {0};
        for (int n : nums) freq[n]++;

        int k = 0, m = 0;

        for (int i = 1; i <= 100; i++)
            if (freq[i] > m) {
                k = 1;
                m = freq[i];
            }
            else if (freq[i] == m) k++;

        return k * m;
    }
};