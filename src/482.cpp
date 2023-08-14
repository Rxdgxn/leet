#include "../include.h"

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ret;
        int curr = k;

        for (int i = s.size() - 1; i >= 0; i--) {
            const char ch = s[i];
            if (ch != '-') {
                ret.push_back(ch >= 'a' && ch <= 'z' ? (ch - 32) : ch);
                curr--;
                if (curr == 0) {
                    ret.push_back('-');
                    curr = k;
                }
            }
        }

        reverse(ret.begin(), ret.end());
        int off = (ret[0] == '-');
        return string(ret.begin() + off, ret.end());
    }
};