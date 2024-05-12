#include "../include.h"

class Solution {
public:
    int mx(vector<int> v) {
        int m = v[0];

        for (int x : v) {
            m = max(m, x);
        }

        return m;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        const int n = grid.size();
        auto ret = vector<vector<int>>(n - 2, vector<int>(n - 2));

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                ret[i][j] = mx({
                    grid[i + 1][j + 1],
                    grid[i + 1][j],
                    grid[i + 1][j + 2],
                    grid[i][j + 1],
                    grid[i][j],
                    grid[i][j + 2],
                    grid[i + 2][j + 1],
                    grid[i + 2][j],
                    grid[i + 2][j + 2]
                });
            }
        }

        return ret;
    }
};