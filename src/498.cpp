#include "../include.h"

class Solution {
public:
    #define IN_BOUND(x, y) (x >= 0 && y >= 0 && x < m && y < n)

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        const int m = mat.size(), n = mat[0].size();
        vector<int> ret;
        ret.reserve(m * n);

        int x = 0, y = 0;
        int dx = -1, dy = 1;

        while (!(x == m - 1 && y == n - 1)) {
            ret.push_back(mat[x][y]);
            
            if (IN_BOUND(x + dx, y + dy)) {
                x += dx;
                y += dy;
                continue;
            }

            if (dy > 0) {
                if (y < n - 1) y += 1;
                else x += 1;

                dx = 1;
                dy = -1;
            }
            else {
                if (x < m - 1) x += 1;
                else y += 1;

                dx = -1;
                dy = 1;
            }
        }

        ret.push_back(mat[x][y]);

        return ret;
    }
};