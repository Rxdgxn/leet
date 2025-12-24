#include "../include.h"

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = 0, ret = 0;

        for (int apples : apple)
            total += apples;

        sort(capacity.begin(), capacity.end());

        while (total > 0) {
            total -= capacity.back();
            capacity.pop_back();
            ret++;
        }

        return ret;
    }
};