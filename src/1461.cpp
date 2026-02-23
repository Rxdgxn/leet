#include "../include.h"

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        const int n = s.size();

        if (n < k)
            return false;

        string curr;
        unordered_set<string> codes;

        for (int i = 0; i < k; i++)
            curr += s[i];

        codes.insert(curr);

        for (int i = k; i < n; i++) {
            curr.erase(curr.begin());
            curr += s[i];

            codes.insert(curr);
        }

        return codes.size() == (1 << k);
    }
};