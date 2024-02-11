#include "../include.h"

class Solution {
public:
    int memo[71][71][71], n, m;

    int dfs(vector<vector<int>>& grid, int i, int c1, int c2) {
        if (i == n || c1 < 0 || c2 < 0 || c1 == m || c2 == m) return 0;
        if (memo[i][c1][c2] != -1) return memo[i][c1][c2];

        int ret = 0, d[] = {-1, 0, 1};

        for (int k1 = 0; k1 < 3; k1++)
            for (int k2 = 0; k2 < 3; k2++)
                ret = max(ret, dfs(grid, i + 1, c1 + d[k1], c2 + d[k2]));
        
        if (c1 == c2) ret += grid[i][c1];
        else ret += grid[i][c1] + grid[i][c2];

        return memo[i][c1][c2] = ret;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        memset(memo, -1, sizeof memo);
        n = grid.size();
        m = grid[0].size();

        return dfs(grid, 0, 0, m - 1);
    }
};