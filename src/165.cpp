#include "../include.h"

class Solution {
public:
    int compareVersion(string s1, string s2) {
        int it1 = 0, it2 = 0, n = s1.size(), m = s2.size();

        while (it1 < n || it2 < m) {
            int x1 = 0, x2 = 0;

            while (it1 < n && s1[it1] != '.') {
                x1 = x1 * 10 + (s1[it1++] - '0');
            }
            it1++;

            while (it2 < m && s2[it2] != '.') {
                x2 = x2 * 10 + (s2[it2++] - '0');
            }
            it2++;

            if (x1 < x2) return -1;
            else if (x1 > x2) return 1;
        }

        return 0;
    }
};