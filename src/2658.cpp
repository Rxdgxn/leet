#include "../include.h"

class Solution {
public:
    int visited[10][10];
    int m, n;

    int dfs(vector<vector<int>>& grid, int i, int j, int visited[10][10]) {
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || grid[i][j] == 0) return 0;

        visited[i][j] = 1;

        return grid[i][j] + dfs(grid, i + 1, j, visited) + dfs(grid, i - 1, j, visited) + dfs(grid, i, j + 1, visited) + dfs(grid, i, j - 1, visited);    
    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int maxFish = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j])
                    maxFish = max(maxFish, dfs(grid, i, j,visited));

        return maxFish;
    }
};