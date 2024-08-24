#include "../include.h"

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        map<int, int> visits;

        const int sz = rounds.size();

        for (int i = 0; i < sz - 1; i++) {
            int x = rounds[i];

            while (x != rounds[i + 1]) {
                visits[x++]++;

                if (x > n) x = 1;
            }
        }
        visits[rounds[sz - 1]]++;

        int mx = 0;
        vector<int> ret;

        for (auto& [k, v] : visits) {
            if (v > mx) {
                ret.clear();
                mx = v;
                ret.push_back(k);
            }
            else if (v == mx) ret.push_back(k);
        }

        return ret;
    }
};