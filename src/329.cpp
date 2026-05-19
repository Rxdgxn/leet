#include "../include.h"

class Solution {
public:
    int m, n;
    vector<vector<int>> longest; // longest path starting from (i, j)

    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {1, -1, 0, 0};

    int dfs(int i, int j, const vector<vector<int>>& matrix) {
        if (longest[i][j] != -1)
            return longest[i][j];

        bool updated = false;

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];

            if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[i][j] < matrix[ni][nj]) {
                longest[i][j] = max(longest[i][j], 1 + dfs(ni, nj, matrix));
                updated = true;
            }
        }

        if (!updated)
            return 0;

        return longest[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        longest = vector<vector<int>>(m, vector<int>(n, -1));

        int ret = -1;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ret = max(ret, dfs(i, j, matrix));

        return ret + 1;
    }
};