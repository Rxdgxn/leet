#include "../include.h"

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie();

        unordered_map<int, int> div_sum;
        int s = 0;

        for (int n : nums) {
            if (div_sum[n]) {
                s += div_sum[n];
                continue;
            }

            int d = 1, k = 0, x = 0;

            while (d * d <= n && k <= 4) {
                if (n % d == 0) {
                    x += d;
                    k++;

                    if (n / d != d) {
                        x += n / d;
                        k++;
                    }
                    else {
                        k = INT_MAX;
                        break;
                    }
                }

                d++;
            }

            if (k == 4) {
                s += x;
                div_sum[n] = x;
            }
        }

        return s;
    }
};