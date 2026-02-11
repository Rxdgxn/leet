#include "../include.h"

class Solution {
public:
    #define MOD (int) (1e9 + 7)

    int monkeyMove(int n) {
        // 00..0000 or 11..1111 (clockwise or anticlockwise)
        // (2^n - 2) % MOD

        long long ret = 1, base = 2;

        while (n > 0) {
            if (n % 2 == 1)
                ret = (ret * base) % MOD;

            base = (base * base) % MOD;
            n /= 2;
        }

        return (ret - 2 + MOD) % MOD;
    }
};