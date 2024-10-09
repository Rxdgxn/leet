#include "../include.h"

class Solution {
public:
    int minAddToMakeValid(string s) {
        int t = 0;
        stack<char> st;

        for (char c : s) {
            if (c == '(') st.push(c);
            else {
                if (!st.empty()) st.pop();
                else t++;
            }
        }

        return t + st.size();
    }
};