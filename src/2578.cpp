#include "../include.h"

class Solution {
public:
    int splitNum(int num) {
        vector<int> v;
        while (num) {
            v.push_back(num % 10);
            num /= 10;
        }
        sort(v.begin(), v.end());

        int n1 = 0, n2 = 0, sz = v.size();
        for (int i = 0; i < sz - 1 - (sz % 2); i += 2) {
            n1 = n1 * 10 + v[i];
            n2 = n2 * 10 + v[i + 1];
        }
        if (sz % 2) {
            n1 = n1 * 10 + v[sz - 1];
        }

        return n1 + n2;
    }
};