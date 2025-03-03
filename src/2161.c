#include <stdlib.h>

int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    *returnSize = numsSize;

    int *ret = malloc(numsSize * sizeof(int));
    int it = 0, occs = 0;

    for (int i = 0; i < numsSize; i++)
        if (nums[i] == pivot) occs++;
        else if (nums[i] < pivot) ret[it++] = nums[i];

    for (int i = 0; i < occs; i++)
        ret[it++] = pivot;

    for (int i = 0; i < numsSize; i++)
        if (nums[i] > pivot) ret[it++] = nums[i];

    return ret;
}