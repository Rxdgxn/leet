#include "../include.h"

class Solution {
public:
    long long minimumSteps(string s) {
        long long steps = 0, count = 0;

        for (char c : s) {
            if (c == '0') {
                steps += count;
            }
            else {
                count++;
            }
        }

        return steps;
    }
};