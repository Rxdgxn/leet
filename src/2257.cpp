#include "../include.h"

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int unguarded = m * n - walls.size();

        vector<vector<char>> grid(m, vector<char>(n, 0));

        for (auto& wall : walls)
            grid[wall[0]][wall[1]] = 'w';

        for (auto& g : guards) {
            grid[g[0]][g[1]] = 'g';
            unguarded--;
        }

        for (auto& g : guards) {
            for (int i = g[0] + 1; i < m; i++) {
                if (grid[i][g[1]] > 1)
                    break;

                if (!grid[i][g[1]]) {
                    unguarded--;
                    grid[i][g[1]] = 1;
                }
            }
            for (int i = g[0] - 1; i >= 0; i--) {
                if (grid[i][g[1]] > 1)
                    break;

                if (!grid[i][g[1]]) {
                    unguarded--;
                    grid[i][g[1]] = 1;
                }
            }

            for (int i = g[1] + 1; i < n; i++) {
                if (grid[g[0]][i] > 1)
                    break;

                if (!grid[g[0]][i]) {
                    unguarded--;
                    grid[g[0]][i] = 1;
                }
            }
            for (int i = g[1] - 1; i >= 0; i--) {
                if (grid[g[0]][i] > 1)
                    break;

                if (!grid[g[0]][i]) {
                    unguarded--;
                    grid[g[0]][i] = 1;
                }
            }
        }

        return unguarded;
    }
};