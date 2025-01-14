#include "../include.h"

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> occ;

        int mx = 0;

        for (int n : nums) {
            if (!occ.count(n)) {
                occ.insert({n, 1});
            }
            else {
                occ[n]++;
            }
        }

        for (auto it = occ.begin(); it != occ.end(); it++) {
            int k = it->first;
            int v = it->second;

            if (occ.count(k - 1)) mx = max(mx, v + occ[k - 1]);
            if (occ.count(k + 1)) mx = max(mx, v + occ[k + 1]);
        }

        return mx;
    }
};