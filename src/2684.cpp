#include "../include.h"

class Solution {
public:
    int max_moves = 0;
    int vis[1001][1001];

    void dfs(int i, int j, const int& m, const int& n, const vector<vector<int>>& grid, int moves) {
        if (vis[i][j]) {
            max_moves = max(max_moves, moves);
            return;
        }

        vis[i][j] = 1;

        if (j < n - 1) {
            if (i > 0 && grid[i - 1][j + 1] > grid[i][j]) {
                dfs(i - 1, j + 1, m, n, grid, moves + 1);
            }
            if (i < m - 1 && grid[i + 1][j + 1] > grid[i][j]) {
                dfs(i + 1, j + 1, m, n, grid, moves + 1);
            }
            if (grid[i][j + 1] > grid[i][j]) {
                dfs(i, j + 1, m, n, grid, moves + 1);
            }
        }

        max_moves = max(max_moves, moves);
    }

    int maxMoves(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        for (int it = 0; it < m; it++) {
            dfs(it, 0, m, n, grid, 0);
        }

        return max_moves;
    }
};