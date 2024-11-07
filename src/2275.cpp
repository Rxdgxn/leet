#include "../include.h"

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ret = 0;

        for (int bit = 0; bit < 32; bit++) {
            int k = 0;

            for (int c : candidates)
                if (c & (1 << bit)) k++;

            ret = (k > ret ? k : ret);
        }

        return ret;
    }
};