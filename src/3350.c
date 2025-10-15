#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int maxIncreasingSubarrays(int* nums, int n) {
    int ret = 0;
    int prev = nums[0];
    int len = 1, prev_len = -1;

    for (int i = 1; i < n; i++) {
        if (prev < nums[i]) {
            len++;
        }
        else {
            ret = max(ret, len / 2);
            ret = max(ret, min(prev_len, len));

            prev_len = len;
            len = 1;
        }

        prev = nums[i];
    }

    ret = max(ret, len / 2);
    ret = max(ret, min(prev_len, len));

    return ret;
}