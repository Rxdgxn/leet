#include "../include.h"

class Solution {
public:
    int numSteps(string s) {
        int ones = count(s.begin(), s.end(), '1'), steps = 0;

        while (!(s.back() == '1' && ones == 1)) {
            if (s.back() == '0') {
                for (int i = s.size() - 1; i > 0; i--)
                    s[i] = s[i - 1];
                
                s[0] = '0';
            }
            else {
                int i;
                for (i = s.size() - 1; i >= 0; i--) {
                    if (s[i] == '1') {
                        s[i] = '0';
                        ones--;
                    }
                    else {
                        s[i] = '1';
                        ones++;
                        break;
                    }
                }

                if (i < 0) {
                    string t;
                    t += '1';
                    ones = 1;
                    t += s;
                    s = t;
                }
            }

            steps++;
        }

        return steps;
    }
};