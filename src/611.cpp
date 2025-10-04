#include "../include.h"

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ret = 0, i = nums.size() - 1;

        while (i >= 0) {
            int j = i - 1;
            int half = nums[i] / 2 + nums[i] % 2;

            while (j >= 0 && nums[j] > half)
                j--;

            // C(n, 2): duos of numbers > half && < current number
            int n = (i - 1 - (j + 1)) + 1;
            ret += n * (n - 1) / 2;

            // each "half" can pair up with numbers higher than it
            int top = j;
            while (j >= 0 && nums[j] == half)
                j--;

            int halves = (top - (j + 1)) + 1;
            ret += halves * n;

            if (2 * half > nums[i]) {
                // C(halves, 2)
                ret += halves * (halves - 1) / 2;
            }

            // for numbers lower than half, search for available numbers
            // a + b > c <=> b > c - a

            while (j >= 0) {
                auto lb = lower_bound(nums.begin(), nums.begin() + i, nums[i] - nums[j] + 1);

                // there is no number big enough such that nums[j] + x > nums[i]
                if (lb == nums.begin() + i)
                    break;

                ret += distance(lb, nums.begin() + i);

                j--;
            }

            i--;
        }

        return ret;
    }
};