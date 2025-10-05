#include "../include.h"

class Solution {
public:
    map<pair<int, int>, bool> pacific, atlantic;
    int m, n;

    void dfs(int i, int j, vector<vector<int>>& heights, map<pair<int, int>, bool>& vis) {
        vis[{i, j}] = true;

        if (i + 1 < m && !vis[{i + 1, j}] && heights[i][j] <= heights[i + 1][j]) dfs(i + 1, j, heights, vis);
        if (j + 1 < n && !vis[{i, j + 1}] && heights[i][j] <= heights[i][j + 1]) dfs(i, j + 1, heights, vis);
        if (i - 1 >= 0 && !vis[{i - 1, j}] && heights[i][j] <= heights[i - 1][j]) dfs(i - 1, j, heights, vis);
        if (j - 1 >= 0 && !vis[{i, j - 1}] && heights[i][j] <= heights[i][j - 1]) dfs(i, j - 1, heights, vis);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        for (int i = 0; i < n; i++) dfs(0, i, heights, pacific);
        for (int i = 0; i < m; i++) dfs(i, 0, heights, pacific);

        for (int i = 0; i < n; i++) dfs(m - 1, i, heights, atlantic);
        for (int i = 0; i < m; i++) dfs(i, n - 1, heights, atlantic);

        vector<vector<int>> ret;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pacific[{i, j}] && atlantic[{i, j}])
                    ret.push_back({i, j});

        return ret;
    }
};