#include "../include.h"

class Solution {
public:
    int partitionString(string s) {
        int parts = 1, m[26] = {0}, c[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            if (m[s[i] - 'a']) {
                parts++;
                memcpy(m, c, sizeof(int) * 26);
                m[s[i] - 'a'] = 1;
            }
            else m[s[i] - 'a'] = 1;
        }

        return parts;
    }
};