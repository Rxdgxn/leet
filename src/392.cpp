#include "../include.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sc = 0, it = 0;
        const int s_sz = s.size(), t_sz = t.size();

        if (s_sz == 0) return true;

        while (it < s_sz && sc < t_sz) {
            if (t[sc] == s[it]) {
                it++;
            }
            sc++;

            if (it == s_sz) return true;
        }

        return false;
    }
};