#include "../include.h"

class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, k = 0;

        while (i < s.size() && k < t.size()) {
            if (s[i] == t[k]) k++;
            i++;
        }

        return t.size() - k;
    }
};