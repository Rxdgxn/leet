#include "include.h"

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<int> sums;
        int sum = 0, m = 0, im = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        m = sum;
        sums.push_back(sum);
        for (int i = k; i < nums.size(); i++) {
            sum -= nums[i - k];
            sum += nums[i];
            sums.push_back(sum);
            if (sum > m) {
                m = sum;
                im = i - k + 1;
            }
        }
        return (double)sums[im] / k * 1.00000;
    }
};