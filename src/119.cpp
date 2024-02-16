#include "../include.h"

class Solution {
public:
    long long comb(int n, int k) {
        if (k == 0) return 1;

        return n * comb(n - 1, k - 1) / k;
    }

    vector<int> getRow(int rowIndex) {
        vector<int> ret;

        int k, it;

        for (k = 0; k <= (rowIndex + 1) / 2; k++)
            ret.push_back((int)comb(rowIndex, k));

        it = k;
        while (it <= rowIndex) ret.push_back(ret[rowIndex - it++]);

        return ret;
    }
};