#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* longestDiverseString(int a, int b, int c) {
    int ca = 0, cb = 0, cc = 0;
    const int n = a + b + c;

    char *s = malloc(sizeof(char) * (n + 1));
    int len = 0;

    for (int i = 0; i < n; i++) {
        if ((a >= b && a >= c && ca < 2) || (a > 0 && (cb == 2 || cc == 2))) {
            s[len++] = 'a';
            a--;
            ca++;
            cb = cc = 0;
        }
        else if ((b >= a && b >= c && cb < 2) || (b > 0 && (ca == 2 || cc == 2))) {
            s[len++] = 'b';
            b--;
            cb++;
            ca = cc = 0;
        }
        else if ((c >= a && c >= b && cc < 2) || (c > 0 && (ca == 2 || cb == 2))) {
            s[len++] = 'c';
            c--;
            cc++;
            ca = cb = 0;
        }
    }

    s[len] = 0;

    return s;
}