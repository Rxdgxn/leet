#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minSteps(string s, string t) {
        int map[26] = {0}, ret = 0;
        const int sz = s.size();

        for (int i = 0; i < sz; i++) {
            map[s[i] - 'a']--;
            map[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            ret += max(0, map[i]);
        }
        
        return ret;
    }
};