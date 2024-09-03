#include "../include.h"

class Solution {
public:
    int getLucky(string s, int k) {
        string t;

        for (char ch : s) t += to_string(ch - 'a' + 1);

        long long x;
        while (k--) {
            x = 0;

            for (char ch : t) x += (ch - '0');

            t = to_string(x);
        }
        
        return static_cast<int>(x);
    }
};