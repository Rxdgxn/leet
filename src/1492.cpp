class Solution {
public:
    int kthFactor(int n, int k) {
        if (n == 1) return 1;

        int hf1[100], hf2[100];
        int i1 = 0, i2 = 0;

        hf1[i1++] = 1;
        hf2[i2++] = n;

        for (int d = 2; d * d <= n; d++) {
            if (n % d == 0) {
                hf1[i1++] = d;
                if (d * d < n) hf2[i2++] = n / d;
            }
        }

        if (k > i1 + i2) return -1;

        if (k - 1 < i1) return hf1[k - 1];
        return hf2[i2 - (k - i1)];
    }
};