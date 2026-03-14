#include "../include.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        int ret = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || matrix[i][j] == '0')
                    dp[i][j] = matrix[i][j] - '0';
                else
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;

                ret = max(ret, dp[i][j]);
            }
        }

        return ret * ret;
    }
};