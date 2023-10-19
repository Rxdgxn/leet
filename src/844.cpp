#include "../include.h"

class Solution {
public:
    #define PROCESS_STACK(str, stk) for (char c : str) \
            if (c == '#') { \
                if (!stk.empty()) stk.pop_back(); \
            } \
            else stk.push_back(c);

    bool backspaceCompare(string s, string t) {
        vector<char> ss, st;

        PROCESS_STACK(s, ss);
        PROCESS_STACK(t, st);

        return ss == st;
    }
};