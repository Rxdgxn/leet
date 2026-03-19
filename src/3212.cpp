#include "../include.h"

class Solution {
public:
    typedef pair<int, int> Pair; // (x, y)

    int numberOfSubmatrices(vector<vector<char>>& grid) {
        const int m = grid.size(), n = grid[0].size();

        vector<vector<Pair>> dp(m, vector<Pair>(n));
        int ret = 0;

        dp[0][0] = {(grid[0][0] == 'X'), (grid[0][0] == 'Y')};

        for (int j = 1; j < n; j++) {
            dp[0][j] = {dp[0][j - 1].first + (grid[0][j] == 'X'), dp[0][j - 1].second + (grid[0][j] == 'Y')};

            if (dp[0][j].first == dp[0][j].second && dp[0][j].first > 0)
                ret++;
        }

        for (int i = 1; i < m; i++) {
            dp[i][0] = {dp[i - 1][0].first + (grid[i][0] == 'X'), dp[i - 1][0].second + (grid[i][0] == 'Y')};

            if (dp[i][0].first == dp[i][0].second && dp[i][0].first > 0)
                ret++;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = {
                    dp[i - 1][j].first + dp[i][j - 1].first - dp[i - 1][j - 1].first + (grid[i][j] == 'X'),
                    dp[i][j - 1].second + dp[i - 1][j].second - dp[i - 1][j - 1].second + (grid[i][j] == 'Y')
                };

                if (dp[i][j].first == dp[i][j].second && dp[i][j].first > 0)
                    ret++;
            }
        }

        return ret;
    }
};