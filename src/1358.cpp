#include "../include.h"

class Solution {
public:
    int numberOfSubstrings(string s) {
        int st = 0, dr = 0, ss = 0;
        unordered_map<char, int> cnt;

        while (dr < s.size()) {
            cnt[s[dr]]++;

            while (cnt.size() == 3) {
                ss += s.size() - dr;

                cnt[s[st]]--;

                if (cnt[s[st]] == 0)
                    cnt.erase(s[st]);

                st++;
            }

            dr++;
        }

        return ss;
    }
};