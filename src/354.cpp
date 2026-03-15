#include "../include.h"

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [&](vector<int>& a, vector<int>& b) {
            if (a[0] != b[0])
                return a[0] < b[0];

            return a[1] > b[1];
        });

        const int n = envelopes.size();

        vector<int> lis;

        for (int i = 0; i < n; i++) {
            auto lb = lower_bound(lis.begin(), lis.end(), envelopes[i][1]);

            if (lb == lis.end())
                lis.push_back(envelopes[i][1]);
            else
                *lb = envelopes[i][1];
        }

        return lis.size();
    }
};