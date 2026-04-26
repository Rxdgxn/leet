#include "../include.h"

class Solution {
public:
    int m, n;
    vector<vector<int>> vis;
    bool cycle = false;

    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {1, -1, 0, 0};

    bool valid(int i, int j, vector<vector<char>>& grid, char val) {
        return i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == val; 
    }

    void dfs(int i, int j, vector<vector<char>>& grid, char val, int prev_i, int prev_j) {
        if (vis[i][j]) {
            cycle = true;
            return;
        }

        vis[i][j] = 1;

        for (int idx = 0; idx < 4; idx++) {
            int ni = i + dx[idx];
            int nj = j + dy[idx];

            if (valid(ni, nj, grid, val) && (ni != prev_i || nj != prev_j))
                dfs(ni, nj, grid, val, i, j);

            if (cycle)
                return;
        }
    }

    bool containsCycle(vector<vector<char>>& grid) {
        vis = vector<vector<int>>(500, vector<int>(500, 0));

        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m && !cycle; i++) {
            for (int j = 0; j < n && !cycle; j++) {
                if (!vis[i][j]) {
                    dfs(i, j, grid, grid[i][j], INT_MIN, INT_MIN);
                }
            }
        }

        return cycle;
    }
};