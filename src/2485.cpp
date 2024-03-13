#include "../include.h"

class Solution {
public:
    int pivotInteger(int n) {
        const int sq = n * (n + 1) / 2;
        const int x = sqrt(sq);

        if (x * x != sq) return -1;
        return x;
    }
};