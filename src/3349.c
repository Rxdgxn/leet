#include <stdbool.h>

bool hasIncreasingSubarrays(int* nums, int n, int k) {
    int prev = nums[0];
    int len = 1, prev_len = -1;

    for (int i = 1; i < n; i++) {
        if (prev < nums[i]) {
            len++;
        }
        else {
            if (len >= 2 * k || (prev_len >= k && len >= k))
                return true;
    
            prev_len = len;
            len = 1;
        }

        prev = nums[i];
    }

    if (len >= 2 * k || (prev_len >= k && len >= k))
        return true;

    return false;
}