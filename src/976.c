#include <stdlib.h>

int fcmp(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

int largestPerimeter(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), fcmp);

    int it = 0;

    while (it < numsSize - 2) {
        if (nums[it] < nums[it + 1] + nums[it + 2])
            return nums[it] + nums[it + 1] + nums[it + 2];

        it++;
    }

    return 0;
}