#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string sortVowels(string s) {
        vector<int> pos;
        vector<char> chars;

        for (int i = 0; i < s.size(); i++)
            if (strchr("aeiouAEIOU", s[i])) {
                pos.push_back(i);
                chars.push_back(s[i]);
            }

        sort(chars.begin(), chars.end());

        for (int i = 0; i < pos.size(); i++)
            s[pos[i]] = chars[i];

        return s;
    }
};