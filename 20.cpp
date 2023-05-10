#include "include.h"

class Solution {
public:
    bool isValid(string s) {
        vector<char> st;

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') st.push_back(ch);
            else {

                if (st.empty()) return false;

                if (ch == ')') {
                    if (st[st.size() - 1] != '(') return false;
                }
                else if (ch == ']') {
                    if (st[st.size() - 1] != '[') return false;
                }
                else {
                    if (st[st.size() - 1] != '{') return false;
                }

                st.pop_back();
            }
        }

        return st.empty();
    }
};