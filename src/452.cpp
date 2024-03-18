#include "../include.h"

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int a = 1, prev = points[0][1], n = points.size();

        for (int i = 1; i < n; i++) {
            if (points[i][0] > prev) {
                prev = points[i][1];
                a++;
            }
        }

        return a;
    }
};