#include "../include.h"

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string ret;

        for (char digit : num) {
            while (k > 0 && !st.empty() && digit < st.top()) {
                k--;
                st.pop();
            }
            st.push(digit);
        }

        while (k > 0 && !st.empty()) {
            k--;
            st.pop();
        }

        while (!st.empty()) {
            ret.push_back(st.top());
            st.pop();
        }

        reverse(ret.begin(), ret.end());

        while (ret[k] == '0' && k < ret.size()) k++;
        
        if (k == ret.size()) return "0";
        return string(ret.begin() + k, ret.end());
    }
};