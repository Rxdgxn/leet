#include "../include.h"

class Solution {
public:
    int minTimeToType(string word) {
        int ops = 0, ptr = 1;

        for (char ch : word) {
            int x = ch - 'a' + 1;
            
            const int d = abs(ptr - x);
            ops += min(d, 26 - d);
            
            ++ops;

            ptr = x;
        }

        return ops;
    }
};