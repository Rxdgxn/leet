#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        const int n = stockPrices.size();

        if (n < 2) return 0;

        sort(stockPrices.begin(), stockPrices.end());

        auto prevStock = stockPrices[0];
        int lines = 1;
        long double prevD = INFINITY;

        for (int i = 1; i < n; i++) {
            long double dx = stockPrices[i][0] - prevStock[0], dy = stockPrices[i][1] - prevStock[1];

            if (dy / dx != prevD && prevD != INFINITY) lines++;

            prevStock = stockPrices[i];
            prevD = dy / dx;
        }

        return lines;
    }
};