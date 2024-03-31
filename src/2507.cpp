class Solution {
public:
    int smallestValue(int n) {
        while (true) {
            int s = 0, cn = n;

            for (int d = 2; d * d <= n; d++) {
                int p = 0;

                while (n % d == 0) {
                    n /= d;
                    p++;
                }

                s += p * d;
            }

            if (n > 1) s += n;

            if (cn == s) return cn;

            n = s;
        }

        return -1;
    }
};