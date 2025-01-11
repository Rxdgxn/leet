#include "../include.h"

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        const int n = nums.size();
        int mx = 0, mi = INT_MAX;

        vector<int> sorted(n);

        for (int i = 0; i < n; i++)
            sorted[i] = i;

        sort(sorted.begin(), sorted.end(), [&](int& i, int& j) {
            return nums[i] != nums[j] ? nums[i] < nums[j] : i < j;
        });

        for (int i = 0; i < n; i++) {
            mi = min(mi, sorted[i]);
            mx = max(mx, sorted[i] - mi);
        }

        return mx;
    }
};