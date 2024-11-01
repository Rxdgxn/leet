#include <string.h>

char* makeFancyString(char* s) {
    char prev = *s;
    char *p = s + 1;

    int occ = 1, i = 0;

    while (*p) {
        if (*p == prev) occ++;
        else occ = 1;

        if (occ <= 2) s[++i] = *p;
        
        prev = *p;
        p++;
    }

    s[i + 1] = 0;

    return s;
}