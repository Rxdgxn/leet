#include "include.h"

class Solution {
public:

    bool cmp(int a, int b) {
        map<int, int> as, bs;
        
        while (a > 9) {
            as[a % 10]++;
            a /= 10;
        }
        as[a]++;
        while (b > 9) {
            bs[b % 10]++;
            b /= 10;
        }
        bs[b]++;

        return as == bs;
    }

    bool reorderedPowerOf2(int n) {
        for (int i = 0; i < 31; i++) {
            if (cmp(n, (1 << i))) return true;
        }

        return false;
    }
};