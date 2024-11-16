#include "../include.h"

class Solution {
public:
    inline long long gauss(long long n) {
        return n * (n + 1) / 2;
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> ret, sp(n + 1);

        sp[0] = 0;

        for (int i = 1; i <= n; i++)
            sp[i] = sp[i - 1] + nums[i - 1];

        for (int i = 1; i <= n - k + 1; i++) {
            if (sp[i + k - 1] - sp[i - 1] == static_cast<int>(gauss(nums[i + k - 2]) - gauss(nums[i - 1] - 1))) {
                ret.push_back(nums[i + k - 2]);
            }
            else {
                ret.push_back(-1);
            }
        }

        return ret;
    }
};