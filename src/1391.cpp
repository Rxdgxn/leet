#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    int visited[300][300];
    int m, n;

    void dfs(const vector<vector<int>>& grid, int i, int j) {
        if (visited[i][j] || visited[m - 1][n - 1]) return;

        visited[i][j] = 1;

        switch (grid[i][j])
        {
        case 1:
            if (j > 0 && (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 || grid[i][j - 1] == 6))
                dfs(grid, i, j - 1);
            if (j < n - 1 && (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 || grid[i][j + 1] == 5))
                dfs(grid, i, j + 1);
            break;
        case 2:
            if (i > 0 && (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 || grid[i - 1][j] == 4))
                dfs(grid, i - 1, j);
            if (i < m - 1 && (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 || grid[i + 1][j] == 6))
                dfs(grid, i + 1, j);
            break;
        case 3: 
            if (j > 0 && (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 || grid[i][j - 1] == 6))
                dfs(grid, i, j - 1);
            if (i < m - 1 && (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 || grid[i + 1][j] == 6))
                dfs(grid, i + 1, j);
            break;
        case 4:
            if (j < n - 1 && (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 || grid[i][j + 1] == 5))
                dfs(grid, i, j + 1);
            if (i < m - 1 && (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 || grid[i + 1][j] == 6))
                dfs(grid, i + 1, j);
            break;
        case 5:
            if (j > 0 && (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 || grid[i][j - 1] == 6))
                dfs(grid, i, j - 1);
            if (i > 0 && (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 || grid[i - 1][j] == 4))
                dfs(grid, i - 1, j);
            break;
        case 6:
            if (j < n - 1 && (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 || grid[i][j + 1] == 5))
                dfs(grid, i, j + 1);
            if (i > 0 && (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 || grid[i - 1][j] == 4))
                dfs(grid, i - 1, j);
            break;
        default:
            break;
        }
    }

    bool hasValidPath(const vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dfs(grid, 0, 0);

        return visited[m - 1][n - 1];
    }
};