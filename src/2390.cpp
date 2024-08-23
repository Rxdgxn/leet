#include "../include.h"

class Solution {
public:
    string removeStars(string s) {
        string st;

        for (char ch : s) {
            if (ch == '*') st.pop_back();
            else st.push_back(ch);
        }

        return st;
    }
};