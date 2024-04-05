#include "../include.h"

class Solution {
public:
    string makeGood(string s) {
        string ret;

        for (int i = 0; i < s.size(); i++) {
            if (ret.empty()) ret.push_back(s[i]);
            else {
                if (abs(ret.back() - s[i]) == 32) ret.pop_back();
                else ret.push_back(s[i]);
            }
        }

        return ret;
    }
};