#include "../include.h"

class Solution {
public:
    #define MOD static_cast<int>(1e9 + 7)

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int m = queries.size();
        vector<int> ret(m), powers;

        int p = 1;
        while (n) {
            if (n & 1) {
                powers.push_back(p);
            }

            p <<= 1;
            n >>= 1;
        }

        for (int i = 0; i < m; i++) {
            int p = powers[queries[i][0]];
            
            for (int j = queries[i][0] + 1; j <= queries[i][1]; j++)
                p = (static_cast<long long>(p) * powers[j]) % MOD;

            ret[i] = p;
        }

        return ret;
    }
};