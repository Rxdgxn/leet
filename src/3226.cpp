#include "../include.h"

class Solution {
public:
    int minChanges(int n, int k) {
        int c = 0;

        for (int i = 0; i < 31; i++) {
            char b1 = (n >> i) & 1;
            char b2 = (k >> i) & 1;

            if (b1 == 1 && b2 == 0) c++;
            else if (b1 == 0 && b2 == 1) return -1;
        }

        return c;
    }
};