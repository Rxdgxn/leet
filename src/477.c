int totalHammingDistance(int* nums, int numsSize) {
    int thd = 0;

    for (int i = 0; i < 32; i++) {
        int c = 0;

        for (int j = 0; j < numsSize; j++)
            c += (nums[j] >> i) & 1;

        thd += c * (numsSize - c);
    }

    return thd;
}