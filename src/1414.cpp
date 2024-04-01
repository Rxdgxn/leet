#include "../include.h"

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int f1 = 0, f2 = 1, f = 1;
        vector<int> fib;
        fib.push_back(1);

        while (f <= k) {
            fib.push_back(f);
            f1 = f2;
            f2 = f;
            f = f1 + f2;
        }

        int i = fib.size() - 1;
        int s = fib[i--], cnt = 1;

        while (i >= 0) {
            if (s + fib[i] <= k) {
                s += fib[i];
                cnt++;
            }

            if (s == k) break;

            i--;
        }

        return cnt;
    }
};