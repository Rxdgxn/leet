int count(int* nums, int numsSize, int idx, int curr, int target) {
    if (idx == numsSize)
        return curr == target;

    int x = count(nums, numsSize, idx + 1, curr, target);
    int y = count(nums, numsSize, idx + 1, curr | nums[idx], target);

    return x + y;
}

int countMaxOrSubsets(int* nums, int numsSize) {
    int mor = 0;

    for (int i = 0; i < numsSize; i++)
        mor |= nums[i];

    return count(nums, numsSize, 0, 0, mor);
}