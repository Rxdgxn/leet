#include <string.h>
#include <stdlib.h>

void shift(char *c, int x) {
    x %= 26;

    unsigned char tmp = *c + x;

    if (tmp > 'z') {
        *c = (char) ('a' + tmp - 'z' - 1);
    }
    else {
        *c = (char) tmp;
    }
}

char* shiftingLetters(char* s, int* shifts, int shiftsSize) {
    int *partial_sums = malloc((shiftsSize + 1) * sizeof(int));
    if (partial_sums == NULL) {
        return NULL;
    }

    partial_sums[shiftsSize - 1] = shifts[shiftsSize - 1];

    for (int i = shiftsSize - 2; i >= 0; i--) {
        partial_sums[i] = (partial_sums[i + 1] + shifts[i]) % 26;
    }

    for (int i = shiftsSize - 1; i >= 0; i--) {
        shift(&s[i], partial_sums[i]);
    }

    free(partial_sums);

    return s;
}