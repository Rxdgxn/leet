#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

// Optimized C++ version
int maximumDifference(int* nums, int n) {
    int m1 = -1, m2 = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] > m2) {
            m1 = max(m1, nums[i] - m2);
        }
        m2 = min(m2, nums[i]);
    }

    return m1;
}