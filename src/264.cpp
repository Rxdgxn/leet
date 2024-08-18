#include "../include.h"

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s;
        s.insert(1);
        
        long long u;
        for (int i = 0; i < n; i++) {
            u = *s.begin();
            s.erase(s.begin());

            s.insert(u * 2);
            s.insert(u * 3);
            s.insert(u * 5);
        }

        return static_cast<int>(u);
    }
};