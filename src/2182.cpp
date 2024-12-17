#include "../include.h"

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int> occ;
        string ret;

        for (char c : s) occ[c]++;

        int current = 0;

        for (char ch = 'z'; ch >= 'a'; ch--) {
            if (current < repeatLimit && occ[ch]) {
                ret += ch;
                current++;

                occ[ch]--;
                ch++;
            }
            else {
                if (current == repeatLimit && occ[ch]) {
                    for (char next = ch - 1; next >= 'a'; next--) {
                        if (occ[next]) {
                            ret += next;

                            occ[next]--;
                            ch++;
                            break;
                        }
                    }
                }

                current = 0;
            }
        }

        return ret;
    }
};