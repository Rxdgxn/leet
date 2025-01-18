#include "../include.h"

class Solution {
public:
    const int dirs[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    int minCost(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});

        vector<vector<int>> minCost(m, vector<int>(n, INT_MAX));
        minCost[0][0] = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int c = curr[0], i = curr[1], j = curr[2];

            if (minCost[i][j] != c) continue;

            for (int d = 0; d < 4; d++) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];

                if (ni >= 0 && nj >= 0 && ni < m && nj < n) {
                    int nc = c + (d + 1 != grid[i][j]);

                    if (minCost[ni][nj] > nc) {
                        minCost[ni][nj] = nc;
                        pq.push({nc, ni, nj});
                    }
                }
            }
        }

        return minCost[m - 1][n - 1];
    }
};