#include "../include.h"

class Solution {
public:
    int maximumLength(string s) {
        s += '.';

        map<pair<char, int>, int> mp;

        int len;

        for (int i = 0; i < s.size(); i++) {
            len = 1;

            mp[{s[i], len}]++;

            for (int j = i; j < s.size() - 1; j++)
                if (s[i] == s[j + 1]) mp[{s[i], ++len}]++;
                else break;
        }

        int mx = -1;

        for (auto it : mp)
            if (it.second >= 3)
                mx = max(mx, it.first.second);

        if (mx == 0) return -1;
        return mx;
    }
};