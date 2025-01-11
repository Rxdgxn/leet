#include "../include.h"

class Solution {
public:
    bool canConstruct(string& s, int k) {
        if (s.size() < k) return false;

        int map[26] = {0};
        int odds = 0;

        for (char& c : s)
            map[c - 'a']++;

        for (int i = 0; i < 26; i++)
            if (map[i] % 2) odds++;

        if (odds > k) return false;
        return true;
    }
};