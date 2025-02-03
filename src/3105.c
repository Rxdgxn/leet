int longestMonotonicSubarray(int* nums, int numsSize) {
    int max = 1, li = 1, ld = 1;
    int prev = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > prev) {
            max = (max < ld ? ld : max);
            ld = 1;
            li++;
        }
        else if (nums[i] < prev) {
            max = (max < li ? li : max);
            li = 1;
            ld++;
        }
        else {
            max = (max < ld ? ld : max);
            max = (max < li ? li : max);
            li = ld = 1;
        }

        prev = nums[i];
    }

    max = (max < ld ? ld : max);
    max = (max < li ? li : max);

    return max;
}