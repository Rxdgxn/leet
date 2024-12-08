#include "../include.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        const int n = height.size();

        int l = 0, r = n - 1;
        int mx = 0;

        while (l < r) {
            mx = max(mx, (r - l) * min(height[l], height[r]));

            if (height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }

        return mx;
    }
};