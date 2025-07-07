#include "../include.h"

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angles;
        int vis = 0, extra = 0;

        for (auto p : points) {
            if (p[0] == location[0] && p[1] == location[1]) {
                extra++;
                continue;
            }

            double rad = atan2(p[1] - location[1], p[0] - location[0]);
            angles.push_back(rad * 180 / acos(-1));
        }

        sort(angles.begin(), angles.end());

        const int n = angles.size();
        for (int i = 0; i < n; i++) {
            angles.push_back(angles[i] + 360);
        }

        int u = 0; // angles[u]

        for (int i = 1; i < angles.size(); i++) {
            if (angles[i] - angles[u] > angle) {
                vis = max(vis, i - u);
                u++;
            }
        }

        return vis + extra;
    }
};