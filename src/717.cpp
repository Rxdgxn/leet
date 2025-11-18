#include "../include.h"

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, n = bits.size();

        while (i < n) {
            if (i == n - 1)
                return true;

            if (bits[i])
                i++;

            i++;
        }

        return false;
    }
};