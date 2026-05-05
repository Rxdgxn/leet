#include "../include.h"

class Solution {
public:
    unordered_map<int, int> ways; // start index -> ways

    int decode(string& s, int i, int n) {
        if (i == n)
            return 1;

        if (s[i] == '0')
            return 0;

        if (ways.find(i) != ways.end())
            return ways[i];

        int d = (i + 1 < n && (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26 ? decode(s, i + 2, n) : 0);

        return ways[i] = decode(s, i + 1, n) + d;
    }

    int numDecodings(string s) {
        return decode(s, 0, s.size());
    }
};