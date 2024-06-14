#include "../include.h"

class Solution {
public:
    string removeDuplicates(string s, int k) {
        // TLE....

        auto t = (char*) s.c_str();
        int sz = strlen(t);

        for (int i = 0; i <= sz - k; i++) {
            int c = count(t + i, t + i + k, t[i]);

            if (c == k) {
                memmove(t + i, t + i + k, sz - (i + k));
                i = -1;
                sz -= k;
            }

        }

        t[sz] = 0;
        string x = t;
        return x;
    }
};