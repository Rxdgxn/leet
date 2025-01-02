#include "../include.h"

class Solution {
public:
    int starts_and_ends(string& s) {
        return strchr("aeiou", s[0]) != NULL && strchr("aeiou", s.back()) != NULL;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        const int sz = words.size();

        vector<int> dp(sz + 1, 0);
        vector<int> ret(queries.size());

        for (int i = 0; i < sz; i++) {
            dp[i + 1] = dp[i] + starts_and_ends(words[i]);
        }

        int it = 0;
        for (auto& p : queries) {
            ret[it++] = dp[p[1] + 1] - dp[p[0]];
        }

        return ret;
    }
};