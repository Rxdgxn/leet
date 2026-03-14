#include "../include.h"

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> memo;

    long long generate(int n, int a, int l) {
        if (a >= 2 || l >= 3)
            return 0;

        if (n == 0)
            return 1;

        const auto tup = make_tuple(n, a, l);

        if (memo[n][a][l] != -1)
            return memo[n][a][l];

        int cnt = generate(n - 1, a, 0);
        cnt = (cnt + generate(n - 1, a + 1, 0)) % MOD;
        cnt = (cnt + generate(n - 1, a, l + 1)) % MOD;

        return memo[n][a][l] = cnt;
    }

    int checkRecord(int n) {
        memo = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return generate(n, 0, 0) % MOD;
    }
};