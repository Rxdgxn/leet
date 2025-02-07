#include "../include.h"

class Solution {
public:
    string freqAlphabets(string s) {
        string mapped;

        for (int i = s.size() - 1; i >= 0; i--)
            if (s[i] == '#') {
                int x = stoi(s.substr(i - 2, 2));
                mapped += ('a' + x - 1);

                i -= 2;
            }
            else {
                mapped += ('a' + s[i] - '0' - 1);
            }
        
        reverse(mapped.begin(), mapped.end());

        return mapped;
    }
};