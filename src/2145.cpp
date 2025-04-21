#include "../include.h"

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        const int n = differences.size();
        
        long long biggest_drop = 0, biggest_spike = 0, s = 0;
        
        for (int i = 0; i < n; i++) {
            s += differences[i];
            biggest_drop = min(biggest_drop, s);
            biggest_spike = max(biggest_spike, s);
        }

        long long first = lower - biggest_drop;

        if (first + biggest_spike > upper)
            return 0;

        return upper - (first + biggest_spike) + 1;
    }
};