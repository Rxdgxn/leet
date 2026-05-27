#include "../include.h"

class Solution {
public:
    // Can be faster by keeping track of max/min row/column for each row & column
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int, set<int>> x_to_ys, y_to_xs;

        for (auto& b : buildings) {
            x_to_ys[b[0]].insert(b[1]);
            y_to_xs[b[1]].insert(b[0]);
        }

        if (next(x_to_ys.begin()) == x_to_ys.end())
            return 0;

        int ret = 0;

        for (auto it = next(x_to_ys.begin()); next(it) != x_to_ys.end(); it++) {
            auto& ys = it->second;
            int curr_x = it->first;

            if (next(ys.begin()) == ys.end())
                continue;

            for (auto yt = next(ys.begin()); next(yt) != ys.end(); yt++) {
                auto& xs = y_to_xs[*yt];
                auto jt = xs.find(curr_x);

                if (jt != xs.begin() && jt != xs.end() && next(jt) != xs.end())
                    ret++;
            }
        }

        return ret;
    }
};