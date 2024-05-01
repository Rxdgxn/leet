#include "../include.h"

class Solution {
public:
    void rev(char *s, int count) {
        int i = 0, j = count - 1;

        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    string reversePrefix(string word, char ch) {
        auto s = (char*) word.c_str();
        char *p = strchr(s, ch);

        if (p != NULL) rev(s, p - s + 1);

        return s;
    }
};