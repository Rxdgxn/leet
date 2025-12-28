#include "../include.h"

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        int i = m - 1, j = 0;

        int ret = 0;

        while (i >= 0 && j < n) {
            if (grid[i][j] < 0) {
                ret += n - j;
                i--;
            }
            else {
                j++;
            }
        }

        return ret;
    }
};