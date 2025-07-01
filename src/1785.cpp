#include "../include.h"

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        
        for (long long n : nums)
            sum += n;

        double rem = abs(sum - goal);

        if (rem == 0)
            return 0;

        return static_cast<int>(ceil(rem / limit));
    }
};