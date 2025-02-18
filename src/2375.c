#include <string.h>
#include <stdlib.h>

void reverse(char *st, char *dr) {
    while (st < dr) {
        char c = *dr;
        *dr = *st;
        *st = c;

        st++;
        dr--;
    }
}

char* smallestNumber(char* pattern) {
    const int n = strlen(pattern);
    char *ret = calloc(n + 2, sizeof(char));

    int x = 1;
    ret[0] = x + '0';

    char *prev = NULL;

    for (int i = 0; i < n; i++) {
        if (pattern[i] == 'I') {
            if (prev != NULL) {
                reverse(prev, ret + i);
                prev = NULL;
            }
        }
        else {
            if (prev == NULL) {
                prev = ret + i;
            }
        }

        ret[i + 1] = ++x + '0';
    }

    if (prev != NULL) {
        reverse(prev, ret + n);
        prev = NULL; // good practice
    }

    return ret;
}