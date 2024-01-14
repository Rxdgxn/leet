#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        int map1[26] = {0}, map2[26] = {0};
        
        const int sz = word1.size();

        for (int i = 0; i < sz; i++) {
            map1[word1[i] - 'a']++;
            map2[word2[i] - 'a']++;
        }

        vector<int> v1, v2;
        vector<int> c1, c2;

        for (int i = 0; i < 26; i++) {
            if (map1[i]) {
                v1.push_back(map1[i]);
                c1.push_back(i);
            }
            if (map2[i]) {
                v2.push_back(map2[i]);
                c2.push_back(i);
            }
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());

        return v1 == v2 && c1 == c2;
    }
};