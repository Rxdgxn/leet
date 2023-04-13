#include "include.h"

class Solution {
public:

    int a[301][301];

    int dfs(const vector<vector<int>>& grid, int i, int j) {
        if (!a[i][j] && grid[i][j]) {
            a[i][j] = 1;
            return 1 + (i > 0 ? dfs(grid, i - 1, j) : 0) + (i < grid.size() - 1 ? dfs(grid, i + 1, j) : 0) + (j > 0 ? dfs(grid, i, j - 1) : 0) + (j < grid[0].size() - 1 ? dfs(grid, i, j + 1) : 0);
        }
        return 0;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!a[i][j]) {
                    area = max(area, dfs(grid, i, j));
                }
            }
        }

        return area;
    }
};