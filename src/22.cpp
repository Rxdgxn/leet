#include "../include.h"

class Solution {
public:
    vector<string> ret;

    void helper(string s, int o, int c, int n) {
        if (o + c == 2 * n) {
            ret.push_back(s);
            return;
        }

        if (o < n) helper(s + '(', o + 1, c, n);
        if (o > c) helper(s + ')', o, c + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        helper("", 0, 0, n);
        return ret;
    }
};