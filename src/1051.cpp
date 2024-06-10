#include "../include.h"

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto copy = heights;
        sort(copy.begin(), copy.end());

        int ret = 0;

        for (int i = 0; i < heights.size(); i++)
            if (copy[i] != heights[i]) ret++;

        return ret;
    }
};