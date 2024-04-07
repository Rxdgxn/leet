#include "../include.h"

class Solution {
public:
    bool checkValidString(string s) {
        int p1 = 0, p2 = 0;

        for (char ch : s) {
            if (ch == '(') {
                p1++;
                p2++;
            }
            else if (ch == ')') {
                p1--;
                p2--;
            }
            else {
                p1++;
                p2--;
            }

            if (p1 < 0) return false;
            if (p2 < 0) p2 = 0;
        }

        return p2 == 0;
    }
};