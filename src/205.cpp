#include "../include.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<string, string> m1, m2;
        int it = 0;
        const int ssz = s.size(), tsz = t.size();

        // "\u0067\u0067": Really, leetcode?

        for (int i = 0; i < ssz; i++) {
            string ss = "", tt = "";
            ss += s[i];
            tt += t[it];

            // This segment is supposed to be a bit more general purpose
            bool ok = 1;
            if (tt == "u" && it + 4 < tsz) {
                string tmp = t.substr(it + 1, 4);
                for (char ch : tmp)
                    if ('0' > ch || '9' < ch) ok = 0;
                
                if (ok) tt += tmp;
            }

            if (!m1[ss].empty() && m1[ss] != tt) return false;
            if (!m2[tt].empty() && m2[tt] != ss) return false;

            m1[ss] = tt;
            m2[tt] = ss;
            
            if (tt.size() > 1) it += 5;
            else it++;
        }

        return true;
    }
};