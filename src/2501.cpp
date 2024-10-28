#include "../include.h"

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        int len = 0;

        for (int num : nums) {
            int k = 0;
            long long x = num;

            while (set.find(x) != set.end()) {
                k++;
                
                if (x * x> 1e5) break;

                x *= x;
            }

            len = max(len, k);
        }

        return len <= 1 ? -1 : len;
    }
};