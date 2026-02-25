#include <stdlib.h>
#include <string.h>

int get_set_bits(int n) {
    int bits = 0;

    while (n > 0) {
        bits += (n & 1);
        n >>= 1;
    }

    return bits;
}

int fcmp(const void *a, const void *b) {
    int m = *(int*)a;
    int n = *(int*)b;

    int b1 = get_set_bits(m);
    int b2 = get_set_bits(n);

    if (b1 != b2)
        return b1 - b2;

    return m - n;
}

int* sortByBits(int* arr, int n, int* returnSize) {
    *returnSize = n;

    int *sorted = malloc(n * sizeof(int));
    memcpy(sorted, arr, n * sizeof(int));

    qsort(sorted, n, sizeof(int), fcmp);

    return sorted;
}