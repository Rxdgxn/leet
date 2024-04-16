#include "../include.h"

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n));

        for (int j = 0; j < n; j++)
            dp[0][j] = matrix[0][j];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = min((j - 1 >= 0 ? dp[i - 1][j - 1] : INT_MAX), min(dp[i - 1][j], (j + 1 < n ? dp[i - 1][j + 1] : INT_MAX))) + matrix[i][j];
            }
        }

        int ret = INT_MAX;
        for (int j = 0; j < n; j++)
            ret = min(ret, dp[n - 1][j]);

        return ret;
    }
};