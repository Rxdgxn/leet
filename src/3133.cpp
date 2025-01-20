#include "../include.h"

class Solution {
public:
    long long minEnd(int nb, int x) {
        // nums[0] = x
        // Facem apoi permutari pt fiecare 0 din x astfel incat sa poata fi inlocuit cu 1
        // {0, 0, 0} -> ... {1, 1, 1}
        // nb este numarator binar
        long long last = x;

        nb--;

        int p = 0;
        while (x) {
            char b = x & 1;

            if (b == 0) {
                last |= (static_cast<long long>((nb & 1)) << p);
                nb >>= 1;
            }

            x >>= 1;
            p++;
        }

        while (nb) {
            last |= (static_cast<long long>((nb & 1)) << p);
            nb >>= 1;
            p++;
        }

        return last;
    }
};