#include "../include.h"

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int d = -1, u = -1, l = INT_MAX, r = -1;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    if (u == -1) u = i; // up bound
                    d = i; // down bound
                    l = min(l, j); // left bound
                    r = max(r, j); // right bound
                }
            }
        }

        return (d - u + 1) * (r - l + 1);
    }
};