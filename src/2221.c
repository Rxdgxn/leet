int triangularSum(int* nums, int n) {
    while (n > 1) {
        n--;

        for (int i = 0; i < n; i++)
            nums[i] = (nums[i] + nums[i + 1]) % 10;
    }

    return nums[0];
}