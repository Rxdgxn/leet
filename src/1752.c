#include <stdbool.h>

bool check(int* nums, int numsSize) {
    int f = nums[0], prev = nums[0], switches = 0;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < prev) {
            switches++;

            if (switches == 2) return false;
        }

        prev = nums[i];
    }

    if (switches == 0) return true;

    return prev <= f;
}