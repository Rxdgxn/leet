#include "../include.h"

class Solution {
public:
    int maxDepth(string s) {
        int d = 0, mx = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(') d++;
            else if (ch == ')') {
                mx = max(mx, d);
                d--;
            }
        }
        return mx;
    }
};