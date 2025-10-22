#include "../include.h"

class Solution {
public:
    inline int distance(int x1, int y1, int x2, int y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }

    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int, int>> points;
        // numeri pt un cadran, aduni pt fiecare punct alte 3 puncte

        for (auto& c : circles) {
            const int r = c[2];
            const int cx = c[0], cy = c[1];

            for (int i = 0; i <= r; i++) {
                for (int j = 0; j <= r; j++) {
                    if (distance(cx, cy, cx + i, cy + j) <= r * r) {
                        points.insert({cx + i, cy + j});
                        points.insert({cx - i, cy + j});
                        points.insert({cx + i, cy - j});
                        points.insert({cx - i, cy - j});
                    }
                    else {
                        break;
                    }
                }
            }
        }

        return points.size();
    }
};