#include "../include.h"

class Solution {
public:
    void rotate_layer(vector<vector<int>>& grid, int rot, int sc, int m, int n) {
        vector<int> tmp;

        for (int i = sc; i < sc + n; i++)
            tmp.push_back(grid[sc][i]);

        for (int i = sc + 1; i < sc + m; i++)
            tmp.push_back(grid[i][sc + n - 1]);

        for (int i = sc + n - 2; i >= sc; i--)
            tmp.push_back(grid[sc + m - 1][i]);

        for (int i = sc + m - 2; i > sc; i--)
            tmp.push_back(grid[i][sc]);

        const int sz = tmp.size(); // = m * n;
        int curr_pos = 0;

        for (int i = sc; i < sc + n; i++) {
            grid[sc][i] = tmp[(curr_pos + rot) % sz];
            curr_pos++;
        }

        for (int i = sc + 1; i < sc + m; i++) {
            grid[i][sc + n - 1] = tmp[(curr_pos + rot) % sz];
            curr_pos++;
        }

        for (int i = sc + n - 2; i >= sc; i--) {
            grid[sc + m - 1][i] = tmp[(curr_pos + rot) % sz];
            curr_pos++;
        }

        for (int i = sc + m - 2; i > sc; i--) {
            grid[i][sc] = tmp[(curr_pos + rot) % sz];
            curr_pos++;
        }
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int start_corner = 0;

        while (m >= 2 && n >= 2) {
            int rot = k % (2 * (n + m - 2));

            rotate_layer(grid, rot, start_corner, m, n);

            start_corner++;
            n -= 2;
            m -= 2;
        }

        return grid;
    }
};