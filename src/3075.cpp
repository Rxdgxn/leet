#include "../include.h"

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ret = 0;

        sort(happiness.begin(), happiness.end(), greater<int>());

        int t = 0;

        for (int i = 0; i < k; i++) {
            ret += max(happiness[i] - t++, 0);
        }

        return ret;
    }
};