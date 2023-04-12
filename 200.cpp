#include "include.h"

class Solution {
public:

    int a[301][301];

    int dfs(const vector<vector<char>>& grid, int i, int j) {
        if (!a[i][j] && grid[i][j] - '0') {
            a[i][j] = 1;
            if (i > 0) {
                dfs(grid, i - 1, j);
            }
            if (i < grid.size() - 1) {
                dfs(grid, i + 1, j);
            }
            if (j > 0) {
                dfs(grid, i, j - 1);
            }
            if (j < grid[0].size() - 1) {
                dfs(grid, i, j + 1);
            }
            return 1;
        }
        return 0;
    }

    int numIslands(const vector<vector<char>>& grid) {
        int isl = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                isl += dfs(grid, i, j);
            }
        }

        return isl;
    }
};