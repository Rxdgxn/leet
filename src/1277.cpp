#include "../include.h"

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        const int bound = min(m, n);

        auto dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

        int squares = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j]) {
                    dp[i + 1][j + 1] = min({dp[i][j], dp[i + 1][j], dp[i][j + 1]}) + 1;
                    squares += dp[i + 1][j + 1];
                }
            }
        }

        return squares;
    }
};