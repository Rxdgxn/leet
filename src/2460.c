#include <stdlib.h>

int* applyOperations(int* nums, int n, int* returnSize) {
    *returnSize = n;

    int *result = malloc(n * sizeof(int));
    int it = 0;
    
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            nums[i] *= 2;
            nums[i + 1] = 0;

            if (nums[i] != 0) {
                result[it++] = nums[i];
            }
        }
        else if (nums[i] != 0) {
            result[it++] = nums[i];
        }
    }

    if (nums[n - 1] != 0) {
        result[it++] = nums[n - 1];
    }

    for (int i = it; i < n; i++)
        result[i] = 0;

    return result;
}