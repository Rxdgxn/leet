#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Compare {
public:
    bool operator() (const vector<int>& a, const vector<int>& b) {
        const double da = sqrt(a[0] * a[0] + a[1] * a[1]);
        const double db = sqrt(b[0] * b[0] + b[1] * b[1]);

        return da > db;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        vector<vector<int>> ret(k);

        for (const auto& point : points) pq.push(point);

        for (int i = 0; i < k; i++) {
            ret[i] = pq.top();
            pq.pop();
        }

        return ret;
    }
};