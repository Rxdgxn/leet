#include "../include.h"

class Solution {
public:
    bool canBeValid(string s, string locked) {
        const int n = s.size();

        if (n % 2) return false;

        stack<int> o, u;

        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                u.push(i);
            }
            else if (s[i] == '(') {
                o.push(i);
            }
            else {
                if (!o.empty()) o.pop();
                else if (!u.empty()) u.pop();
                else return false;
            }
        }

        while (!o.empty() && !u.empty()) {
            if (o.top() > u.top()) return false;

            o.pop();
            u.pop();
        }

        return o.empty();
    }
};