#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        const int n = profit.size();
        
        vector<pair<int, int>> vec(n);

        for (int i = 0; i < n; i++)
            vec[i] = {difficulty[i], profit[i]};

        sort(vec.begin(), vec.end());
        sort(worker.begin(), worker.end());

        int p = 0, last = 0;

        for (int w : worker) {
            int j = last, k = 0;

            while (j < n && vec[j].first <= w) {
                if (k < vec[j].second) {
                    k = vec[j].second;
                    last = j;
                }
                j++;
            }

            if (j > 0) p += k;
        }

        return p;
    }
};