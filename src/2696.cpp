#include "../include.h"

class Solution {
public:
    void mystrcpy(char *dest, char *src) {
        while (*src != 0) *(dest++) = *(src++);
        *dest = 0;
    }

    int minLength(string str) {
        auto s = (char*) str.c_str();

        for (;;) {
            char *a = strstr(s, "AB");
            if (a != NULL) mystrcpy(a, a + 2);

            char *c = strstr(s, "CD");
            if (c != NULL) mystrcpy(c, c + 2);

            if (a == NULL && c == NULL) break;
        }

        return strlen(s);
    }
};