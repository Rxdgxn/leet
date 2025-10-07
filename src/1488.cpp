#include "../include.h"

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        const int n = rains.size();
        vector<int> ret(n, -1);

        unordered_map<int, int> full;
        set<int> saved;

        for (int i = 0; i < n; i++) {
            const int val = rains[i];

            if (val > 0) {
                if (full.find(val) != full.end()) {
                    auto it = saved.lower_bound(full[val]);
                    
                    if (it == saved.end())
                        return {};

                    full.erase(val);
                    ret[*it] = val;
                    saved.erase(*it);
                }

                full.insert({val, i});
            }
            else {
                saved.insert(i);
            }
        }

        for (auto it = saved.begin(); it != saved.end(); it++)
            ret[*it] = 1;

        return ret;
    }
};