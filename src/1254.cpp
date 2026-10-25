#include "../include.h"

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        const int dx[4] = {-1, 1, 0, 0};
        const int dy[4] = {0, 0, -1, 1};

        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 1;

                    bool closed = true;

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k], ny = y + dy[k];

                            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                                closed = false;
                                continue;
                            }

                            if (grid[nx][ny] == 0) {
                                grid[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }

                    if (closed) {
                        islands++;
                    }
                }
            }
        }

        return islands;
    }
};