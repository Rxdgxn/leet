#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);

        int w = 0, l = points[0][0];

        for (const auto& p : points) {
            w = max(w, p[0] - l);
            l = p[0];
        }

        return w;
    }
};