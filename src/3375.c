#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(const int*)a - *(const int*)b;
}

int minOperations(int* nums, int n, int k) {
    int ops = 0;

    qsort(nums, n, sizeof(int), &cmp);

    int prev = nums[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] != prev)
            ops++;

        prev = nums[i];
    }

    if (prev < k) return -1;
    if (prev > k) ops++;

    return ops;
}