#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    int firstUniqChar(string s) {
        int map[26] = {0}, list[26], idx[26], k = 0;

        for (int i = 0; i < s.size(); i++) {
            const int x = s[i] - 'a';

            if (map[x] == 0) {
                list[k++] = x;
                idx[x] = i;
            }

            map[x]++;
        }

        for (int i = 0; i < k; i++)
            if (map[list[i]] == 1) return idx[list[i]];

        return -1;
    }
};