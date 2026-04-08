#include "../include.h"

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        int land = 0;

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    land++;

                    if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
                        q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (visited[i][j])
                continue; // for those who were already in queue, from the border

            visited[i][j] = 1;
            land--;

            if (i - 1 > 0 && !visited[i - 1][j] && grid[i - 1][j])
                q.push({i - 1, j});
            if (j - 1 > 0 && !visited[i][j - 1] && grid[i][j - 1])
                q.push({i, j - 1});
            if (i + 1 < m - 1 && !visited[i + 1][j] && grid[i + 1][j])
                q.push({i + 1, j});
            if (j + 1 < n - 1 && !visited[i][j + 1] && grid[i][j + 1])
                q.push({i, j + 1});
        }

        return land;
    }
};