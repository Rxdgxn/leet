#include "../include.h"

class Solution {
public:
    #define SUM ((7 * 8) / 2)

    int totalMoney(int n) {
        int w = n / 7, d = n % 7, s = 0;

        for (int k = w + 1; k <= w + d; k++) s += k;

        return w * SUM + 7 * ((w * (w - 1)) / 2) + s;
    }
};