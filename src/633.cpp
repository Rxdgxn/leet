// Baremetal solution

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long a = 0; a * a <= c; a++) {
            int b_sq = c - a * a;
            bool ok = 1;

            for (long long d = 2; d * d <= b_sq && ok; d++) {
                int p = 0;

                while (b_sq % d == 0) {
                    b_sq /= d;
                    p++;
                }

                if (p && p % 2) ok = 0;
            }

            if (b_sq > 1) ok = 0;

            if (ok) return true;
        }

        return false;
    }
};