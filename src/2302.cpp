#include "../include.h"

class Solution {
public:
    using ll = long long;

    ll countSubarrays(vector<int>& nums, ll k) {
        ll ret = 0, sum = 0;
        int i = 0, j = 0, n = nums.size();

        while (j < n) {
            sum += nums[j];

            while (i <= j && sum * (j - i + 1) >= k) {
                sum -= nums[i];
                i++;
            }

            ret += j - i + 1;
            j++;
        }

        return ret;
    }
};