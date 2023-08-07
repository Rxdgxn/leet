#include "../include.h"

class Solution {
public:
    int maxDistToClosest(const vector<int>& seats) {
        int d = 0, m = 0, f = 0;
        vector<int> v;

        while (!seats[f]) f++;
        m = f;

        for (int i = f; i < seats.size(); i++) {
            if (!seats[i]) {
                d++;
            }
            else if (d) {
                v.push_back(d);
                d = 0;
            }
        }

        if (!seats[seats.size() - 1]) m = max(m, d);

        for (int i = 0; i < v.size(); i++) {
            m = max(m, (int)ceil(v[i] / 2.0));
        }

        return m;
    }
};