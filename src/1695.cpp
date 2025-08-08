#include "../include.h"

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> index_in_array;
        int offset = -1;
        int ret = 0;

        const int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
            dp[i] = dp[i - 1] + nums[i];

        for (int i = 0; i < n; i++) {
            if (index_in_array.find(nums[i]) != index_in_array.end() && index_in_array[nums[i]] >= offset) {
                if (offset < 0)
                    ret = dp[i - 1];
                else
                    ret = max(ret, dp[i - 1] - dp[offset]);

                offset = index_in_array[nums[i]];
            }

            index_in_array[nums[i]] = i;
        }

        if (offset < 0)
            ret = dp[n - 1];
        else
            ret = max(ret, dp[n - 1] - dp[offset]);

        return ret;
    }
};