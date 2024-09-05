#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ret(n);
        int m = rolls.size(), s = 0;

        for (int roll : rolls) s += roll;

        int remaining = mean * (m + n) - s;
        int avg = remaining / n, x = remaining % n;

        if (avg > 6 || avg == 0 || remaining < 0) return {};

        for (int i = 0; i < n; i++) ret[i] = avg;

        int i = n - 1;
        while (x && i >= 0) {
            if (ret[i] >= 6) i--;
            else {
                ret[i]++;
                x--;
            }
        }

        if (x) return {};

        return ret;
    }
};