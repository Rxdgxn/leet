#include "../include.h"

class Solution {
public:
    #define MOD 1000000007

    vector<vector<vector<int>>> memo;
    
    int helper(int m, int n, int N, int i, int j) {
        if (i == m || j == n || i < 0 || j < 0) return 1;
        if (N == 0) return 0;

        if (memo[i][j][N] >= 0) return memo[i][j][N];

        memo[i][j][N] = ((helper(m, n, N - 1, i - 1, j)
            + helper(m, n, N - 1, i + 1, j)) % MOD
            + (helper(m, n, N - 1, i, j - 1)
            + helper(m, n, N - 1, i, j + 1)) % MOD) % MOD;

        return memo[i][j][N];
    }

    int findPaths(int m, int n, int N, int i, int j) {
        memo = vector<vector<vector<int>>>(51, vector<vector<int>>(51, vector<int>(51, -1)));
        return helper(m, n, N, i, j);
    }
};