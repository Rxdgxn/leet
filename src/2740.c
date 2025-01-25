#include <stdlib.h>

int fcmp(const void *a, const void *b) {
    return *((const int*)a) - *((const int*)b);
}

int findValueOfPartition(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), fcmp);

    int mn = INT_MAX;

    for (int i = 0; i < numsSize - 1; i++) {
        const int diff = nums[i + 1] - nums[i];

        mn = (mn > diff ? diff : mn);
    }

    return mn;
}