#include "../include.h"

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int i = columnTitle.size() - 1;
        long long p = 1, ret = 0;

        while (i >= 0) {
            ret = ret + (columnTitle[i] - 'A' + 1) * p;
            p *= 26;

            i--;
        }

        return ret;
    }
};