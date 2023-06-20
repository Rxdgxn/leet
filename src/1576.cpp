#include "../include.h"

class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '?') {
                if (i == 0) s[i] = (s[i+1] - 1 < 'a' || s[i+1] == '?' ? 'z' : s[i+1] - 1);
                else {
                    auto x = s[i-1] + 1;
                    if (x > 'z') x -= 26;
                    s[i] = s[i-1] + 1 + (s[i+1] == x ? 1 : 0);
                }
            }
            if (s[i] > 'z') s[i] -= 26;
        }

        return s;
    }
};