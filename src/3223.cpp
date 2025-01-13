#include "../include.h"

class Solution {
public:
    int minimumLength(string s) {
        int occ[26] = {0};

        const int n = s.size();
        int rem = 0;

        for (int i = 0; i < n; i++)
            occ[s[i] - 'a']++;

        for (int i = 0; i < 26; i++)
            rem += (occ[i] % 2 ? 1 : (occ[i] ? 2 : 0));

        return rem;
    }
};