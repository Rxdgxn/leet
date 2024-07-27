#include "../include.h"

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if ((num - 3) % 3) return {};

        const long long a = (num - 3) / 3;

        return {a, a + 1, a + 2};
    }
};