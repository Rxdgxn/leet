#include "../include.h"

class Solution {
public:
    void reverseString(vector<char>& s) {
        const int sz = s.size();

        for (int i = 0; i < sz / 2; i++) {
            const int a = s[i];
            s[i] = s[sz - 1 - i];
            s[sz - 1 - i] = a;
        }
    }
};