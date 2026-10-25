#include "../include.h"

// Generally speaking, maybe a quadtree would be best for this type of problem
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int r = radius * radius;
        int best_q = -1;
        int cx = 0, cy = 0;

        for (int x = 0; x <= 50; x++) {
            for (int y = 0; y <= 50; y++) {
                int q = 0;

                for (auto& t : towers) {
                    int dist = (t[0] - x) * (t[0] - x) + (t[1] - y) * (t[1] - y);

                    if (dist <= r) {
                        q += floor((float)t[2] / (1 + sqrt((float)dist)));
                    }
                }

                if (q > best_q) {
                    best_q = q;
                    cx = x;
                    cy = y;
                }
            }
        }

        return {cx, cy};
    }
};