#include "../include.h"

class Solution {
public:
    int minSwaps(string s) {
        int u = 0;
        stack<char> st;

        for (char ch : s) {
            if (ch == '[') st.push(ch);
            else {
                if (!st.empty()) st.pop();
                else u++;
            }
        }

        return (u + 1) / 2;
    }
};