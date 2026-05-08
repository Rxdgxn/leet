#include "../include.h"

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<vector<int>> times(n, vector<int>(n, INT_MAX)); // time to reach cell (i, j) from (0, 0)
        vector<vector<int>> visited(n, vector<int>(n, 0));

        times[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // [time, i, j]

        pq.push({grid[0][0], 0, 0, 0});

        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int time = top[0], i = top[1], j = top[2];

            if (visited[i][j])
                continue;

            visited[i][j] = 1;

            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];

                if (ni < 0 || nj < 0 || ni >= n || nj >= n)
                    continue;

                int new_time = time + max(0, grid[ni][nj] - time);

                if (times[ni][nj] > new_time) {
                    times[ni][nj] = new_time;
                    pq.push({max(time, grid[ni][nj]), ni, nj, new_time});
                }
            }
        }

        return times[n - 1][n - 1];
    }
};