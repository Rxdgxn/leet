#include "../include.h"

class Solution {
public:
    int time = 0, total = 0;
    int m, n;

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                const int col = grid[i][j];

                if (col) {
                    total++;
                    if (col == 2) q.push({i, j});
                }
            }

        while (!q.empty()) {
            int k = q.size();
            total -= k;

            while (k--) {
                auto p = q.front();
                q.pop();

                const int i = p.first, j = p.second;

                if (i + 1 < m && grid[i + 1][j] == 1) {
                    q.push({i + 1, j});
                    grid[i + 1][j] = 2;
                }
                if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                    q.push({i - 1, j});
                    grid[i - 1][j] = 2;
                }
                if (j + 1 < n && grid[i][j + 1] == 1) {
                    q.push({i, j + 1});
                    grid[i][j + 1] = 2;
                }
                if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                    q.push({i, j - 1});
                    grid[i][j - 1] = 2;
                }
            }

            if (!q.empty()) time++;
        }

        if (total == 0) return time;
        return -1;
    }
};