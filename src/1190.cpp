#include "../include.h"

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> pos;

        for (int i = 0; i < s.size(); i++) {
            const char ch = s[i];

            if (ch == '(') {
                pos.push(i);
            }
            else if (ch == ')') {
                reverse(s.begin() + pos.top() + 1, s.begin() + i);

                s.erase(s.begin() + pos.top()); 
                s.erase(s.begin() + i - 1);

                i -= 2;
                
                pos.pop();
            }
        }

        return s;
    }
};