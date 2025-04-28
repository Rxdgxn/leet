#include "../include.h"

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        const int n = nums.size();

        for (int i = 0; i < n; i++)
            nums[i] = (nums[i] % modulo == k);

        vector<int> dp(n);
        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
            dp[i] = dp[i - 1] + nums[i];

        long long ret = 0;

        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int i = 0; i < n; i++) {
            ret += mp[(dp[i] - k + modulo) % modulo];
            mp[dp[i] % modulo]++;
        }

        return ret;
    }
};