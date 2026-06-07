#include "../include.h"

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        // sort rectangles by top coordinate, then right coord
        vector<vector<int>> corners(101); // y coord

        for (auto& r : rectangles)
            corners[r[1]].push_back(r[0]);

        for (int y = 0; y <= 100; y++)
            sort(corners[y].begin(), corners[y].end());

        const int n = points.size();
        vector<int> ret(n);

        for (int i = 0; i < n; i++) {
            int x = points[i][0];

            int total = 0;

            for (int y = points[i][1]; y <= 100; y++) {
                auto& xs = corners[y];
                auto lb = lower_bound(xs.begin(), xs.end(), x);
                total += distance(lb, xs.end());
            }

            ret[i] = total;
        }

        return ret;
    }
};