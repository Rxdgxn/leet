#include "../include.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
        const int sz = s1.size();

        if (s2.size() < sz) return false;
        
        for (int i = 0; i <= s2.size() - sz; i++) {
            auto tmp = s2.substr(i, sz);
            sort(tmp.begin(), tmp.end());
            if (tmp == s1) return true;
        }

        return false;
    }
};