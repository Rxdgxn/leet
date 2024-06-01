#include "../include.h"

class Solution {
public:
    void back(long long n, int steps, int& ret) {
        if (n == 1) {
            ret = min(ret, steps);
            return;
        }

        if (n % 2 == 0) back(n / 2, steps + 1, ret);
        else {
            back(n - 1, steps + 1, ret);
            back(n + 1, steps + 1, ret);
        }
    }

    int integerReplacement(int n) {
        int ret = INT_MAX;
        back(n, 0, ret);
        
        return ret;
    }
};