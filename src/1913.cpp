#include "../include.h"

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int mx1 = 0, mx2 = 0, mi1 = INT_MAX, mi2 = INT_MAX;

        for (int n : nums) {
            if (n < mi1) {
                mi2 = mi1;
                mi1 = n;
            }
            else if (n < mi2) mi2 = n;

            if (n > mx1) {
                mx2 = mx1;
                mx1 = n;
            }
            else if (n > mx2) mx2 = n;
        }

        return mx1 * mx2 - mi1 * mi2;
    }
};