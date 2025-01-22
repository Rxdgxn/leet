#include "../include.h"

class Solution {
public:
    const int dirs[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int m = isWater.size();
        const int n = isWater[0].size();

        queue<pair<int, int>> q;

        vector<vector<int>> cellHeights(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (isWater[i][j]) {
                    cellHeights[i][j] = 0;
                    q.push({i, j});
                }

        int next = 1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto p = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    const int ni = p.first + dirs[d][0];
                    const int nj = p.second + dirs[d][1];

                    if (ni >= 0 && nj >= 0 && ni < m && nj < n && cellHeights[ni][nj] == -1) {
                        cellHeights[ni][nj] = next;
                        q.push({ni, nj});
                    }
                }
            }

            next++;
        }

        return cellHeights;
    }
};