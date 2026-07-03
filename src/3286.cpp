#include "../include.h"

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        const int m = grid.size(), n = grid[0].size();

        priority_queue<vector<int>> pq; // (lives, i, j)
        vector<vector<int>> lives_till(m, vector<int>(n, -1));

        pq.push({health - grid[0][0], 0, 0});
        lives_till[0][0] = health;

        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};

        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();

            int h = t[0], i = t[1], j = t[2];

            if (h == 0)
                continue;

            if (i == m - 1 && j == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];

                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    if (grid[ni][nj] == 0 && h > lives_till[ni][nj]) {
                        pq.push({h, ni, nj});
                        lives_till[ni][nj] = h;
                    }
                    else if (grid[ni][nj] == 1 && h - 1 > lives_till[ni][nj]) {
                        pq.push({h - 1, ni, nj});
                        lives_till[ni][nj] = h - 1;
                    }
                }
            }
        }

        return false;
    }
};