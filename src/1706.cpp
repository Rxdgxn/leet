#include "../include.h"

class Solution {
public:
    struct Ball {
        int row, col, tag;
    };

    vector<int> findBall(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();

        queue<Ball> balls;
        for (int i = 0; i < n; i++)
            balls.push({0, i, i});

        vector<int> ret(n, -1);

        do {
            int sz = balls.size();

            while (sz--) {
                auto b = balls.front();
                balls.pop();

                if (b.row == m) {
                    ret[b.tag] = b.col;
                    continue;
                }

                if (grid[b.row][b.col] == 1 && b.col < n - 1 && grid[b.row][b.col + 1] == 1)
                    balls.push({b.row + 1, b.col + 1, b.tag});
                else if (grid[b.row][b.col] == -1 && b.col > 0 && grid[b.row][b.col - 1] == -1)
                    balls.push({b.row + 1, b.col - 1, b.tag});
            }

        } while (!balls.empty());

        return ret;
    }
};