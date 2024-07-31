#include <string.h>

char* truncateSentence(char* s, int k) {
    char *p = strchr(s, ' ');
    k--;

    while (k--) {
        p = strchr(p + 1, ' ');
    }

    if (p != NULL) *p = 0;

    return s;
}