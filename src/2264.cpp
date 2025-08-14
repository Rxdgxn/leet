#include "../include.h"

class Solution {
public:
    string largestGoodInteger(string num) {
        string ret = "";
        int max = -1, n;

        for (int i = 0; i <= num.size() - 3; i++) {
            if (num[i] != num[i + 1] || num[i] != num[i + 2])
                continue;

            if (num[i] - '0' > max) {
                max = num[i] - '0';
                ret = "";
                ret = ret + num[i] + num[i + 1] + num[i + 2];
            }
        }

        return ret;
    }
};