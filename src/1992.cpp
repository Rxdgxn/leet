#include "../include.h"

class Solution {
public:
    int m, n;
    int visited[300][300];

    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<int>>& land, int i, int j, int& bi, int& bj) {
        visited[i][j] = 1;

        bi = max(bi, i);
        bj = max(bj, j);

        for (const auto& dir : dirs) {
            int ni = i + dir[0], nj = j + dir[1];

            if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj] && land[ni][nj])
                dfs(land, ni, nj, bi, bj); 
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();

        vector<vector<int>> ret;        

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (land[i][j] && !visited[i][j]) {
                    int bi = -1, bj = -1;
                    dfs(land, i, j, bi, bj);
                    ret.push_back({i, j, bi, bj});
                }

        return ret;
    }
};