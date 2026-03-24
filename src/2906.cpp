#include "../include.h"

class Solution {
public:
    typedef vector<vector<int>> Matrix;
    const int MOD = 12345;

    Matrix constructProductMatrix(Matrix& grid) {
        const int n = grid.size(), m = grid[0].size();

        Matrix pre(n, vector<int>(m)), suf(n, vector<int>(m));

        pre[0][0] = grid[0][0] % MOD;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i != 0 || j != 0) {
                    if (j == 0) {
                        pre[i][j] = ((long long)pre[i - 1][m - 1] * grid[i][j]) % MOD;
                    }
                    else {
                        pre[i][j] = ((long long)pre[i][j - 1] * grid[i][j]) % MOD;
                    }
                }
            }
        }

        suf[n - 1][m - 1] = grid[n - 1][m - 1] % MOD;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i != n - 1 || j != m - 1) {
                    if (j == m - 1) {
                        suf[i][j] = ((long long)suf[i + 1][0] * grid[i][j]) % MOD;
                    }
                    else {
                        suf[i][j] = ((long long)suf[i][j + 1] * grid[i][j]) % MOD;
                    }
                }
            }
        }

        Matrix ret(n, vector<int>(m));

        if (m >= 2) {
            ret[0][0] = suf[0][1];
            ret[n - 1][m - 1] = pre[n - 1][m - 2];
        
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!(i == 0 && j == 0) && !(i == n - 1 && j == m - 1)) {
                        if (j == 0) {
                            ret[i][j] = ((long long)pre[i - 1][m - 1] * suf[i][j + 1]) % MOD;
                        }
                        else if (j == m - 1) {
                            ret[i][j] = ((long long)pre[i][j - 1] * suf[i + 1][0]) % MOD;
                        }
                        else {
                            ret[i][j] = ((long long)pre[i][j - 1] * suf[i][j + 1]) % MOD;
                        }
                    }
                }
            }
        }
        else {
            ret[0][0] = suf[1][0];
            ret[n - 1][0] = pre[n - 2][0];

            for (int i = 1; i < n - 1; i++) {
                ret[i][0] = ((long long)pre[i - 1][0] * suf[i + 1][0]) % MOD;
            }
        }

        return ret;
    }
};