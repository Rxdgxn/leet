#include "../include.h"

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, set<int>> indices;
        const int n = nums.size();

        for (int i = 0; i < n; i++)
            indices[nums[i]].insert(i);

        vector<int> ret;

        for (int q : queries) {
            set<int>& s = indices[nums[q]];

            if (s.size() == 1) {
                ret.push_back(-1);
                continue;
            }

            auto lb = s.lower_bound(q);
            auto nxt = next(lb);
            auto prv = prev(lb);

            if (lb == s.begin()) {
                int lst = *s.rbegin();

                ret.push_back(min(*nxt - q, n - lst + q));
                continue;
            }

            if (nxt == s.end()) {
                int first = *s.begin();

                ret.push_back(min(q - *prv, n - q + first));
                continue;
            }

            ret.push_back(min(q - *prv, *nxt - q));
        }

        return ret;
    }
};