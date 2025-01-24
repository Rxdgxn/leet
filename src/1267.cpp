#include "../include.h"

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        vector<int> row(m, 0), col(n, 0);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) {
                    row[i]++;
                    col[j]++;
                }

        int communicating = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) communicating += (row[i] > 1 || col[j] > 1);

        return communicating;
    }
};