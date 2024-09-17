#include "../include.h"

class Solution {
public:
    vector<vector<int>> dirs = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    void fill(vector<vector<int>>& grid, int i, int j, int n) {
        grid[i][j] = 1;

        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            for (auto& dir : dirs) {
                int x = dir[0] + p.first, y = dir[1] + p.second;

                if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 0) {
                    grid[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int regions = 0;

        const int n = grid.size();

        auto extended = vector<vector<int>>(3 * n, vector<int>(3 * n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int idx = 3 * i, jdx = 3 * j;

                if (grid[i][j] == '/') {
                    extended[idx][jdx + 2] = 1;
                    extended[idx + 1][jdx + 1] = 1;
                    extended[idx + 2][jdx] = 1;
                }
                else if (grid[i][j] == '\\') {
                    extended[idx][jdx] = 1;
                    extended[idx + 1][jdx + 1] = 1;
                    extended[idx + 2][jdx + 2] = 1;
                }
            }
        }

        for (int i = 0; i < 3 * n; i++) {
            for (int j = 0; j < 3 * n; j++) {
                if (extended[i][j] == 0) {
                    fill(extended, i, j, 3 * n);
                    regions++;
                }
            }
        }

        return regions;
    }
};