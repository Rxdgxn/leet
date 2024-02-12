#include <stdbool.h>

int majorityElement(int* nums, int numsSize) {
    bool s;

    do {
        s = true;

        for (int i = 0; i < numsSize - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                int aux = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = aux;

                s = false;
            }
        }
    } while (!s);

    int u = nums[0], ap = 1;
    for (int i = 1; i < numsSize && ap <= numsSize / 2; i++) {
        if (nums[i] == u) ap++;
        else {
            ap = 1;
            u = nums[i];
        }
    }

    return u;
}