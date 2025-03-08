#include "../include.h"

class Solution {
public:
    vector<int> numOfBurgers(int t, int c) {
        // t = 4j + 2s
        // c = j + s
        const int x = 4 * c - t;
        
        if (x < 0 || x % 2 != 0) return {};

        const int s = x / 2, j = c - s;

        if (j < 0) return {};

        return {j, s};
    }
};