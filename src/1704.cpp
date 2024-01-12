#include "../include.h"

class Solution {
public:
    bool halvesAreAlike(string s) {
        const char vowels[] = "aeiouAEIOU";
        
        int k1 = 0, k2 = 0;
        const int half = s.size() / 2;

        for (int i = 0; i < half; i++)
            if (strchr(vowels, s[i]) != NULL) k1++;

        for (int i = half; i < 2 * half; i++)
            if (strchr(vowels, s[i]) != NULL) k2++;

        return k1 == k2;
    }
};