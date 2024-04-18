#include "../include.h"

class Solution {
public:
    int m, n;

    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited) {
        if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 0) return 1;

        if (visited[i][j]) return 0;

        visited[i][j] = 1;

        return  dfs(grid, i + 1, j, visited) +
                dfs(grid, i, j + 1, visited) +
                dfs(grid, i - 1, j, visited) +
                dfs(grid, i, j - 1, visited);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) return dfs(grid, i, j, visited);
        
        return -1;
    }
};