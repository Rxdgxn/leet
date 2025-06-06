#include "../include.h"

class Solution {
public:
    string robotWithString(string s) {
        string ret;

        int map[26] = {0};
        stack<char> st;

        for (char c : s)
            map[c - 'a']++;

        int m = 0;
        for (char c : s) {
            st.push(c);
            map[c - 'a']--;

            while (m + 'a' != 'z' && map[m] == 0) {
                m++;
            }

            while (!st.empty() && st.top() <= m + 'a') {
                ret += st.top();
                st.pop();
            }
        }

        return ret;
    }
};