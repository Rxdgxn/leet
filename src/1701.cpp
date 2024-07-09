#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double avg = customers[0][1];
        int t = customers[0][0] + customers[0][1];

        const int n = customers.size();

        for (int i = 1; i < n; i++) {
            if (customers[i][0] <= t) {
                t += customers[i][1];
                avg += (t - customers[i][0]);
            }
            else {
                t = customers[i][0] + customers[i][1];
                avg += customers[i][1];
            }
        }

        return avg / n;
    }
};