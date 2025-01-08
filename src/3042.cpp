#include "../include.h"

class Solution {
public:
    int helper(string& a, string& b) {
        const int an = a.size(), bn = b.size();

        if (an > bn) return 0;

        return b.substr(0, an) == a && b.substr(bn - an) == a;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        const int n = words.size();
        int pairs = 0;

        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                pairs += helper(words[i], words[j]);

        return pairs;
    }
};