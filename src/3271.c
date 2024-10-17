#include <string.h>
#include <stdlib.h>

char* stringHash(char* s, int k) {
    int p = 0, n = strlen(s);

    char *ret = malloc(sizeof(char) * (n / k + 1));
    int len = 0;

    while (p <= n - 1) {
        int sum = 0;

        for (int i = p; i < p + k; i++) {
            sum += (s[i] - 'a');
        }

        ret[len++] = 'a' + sum % 26;

        p += k;
    }

    ret[len] = 0;

    return ret;
}