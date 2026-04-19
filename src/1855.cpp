#include "../include.h"

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ret = 0;
        const int n = nums1.size(), m = nums2.size();

        int i = 0, j = 0;
        
        while (i < n && j < m) {
            if (nums1[i] > nums2[j]) {
                i++;
                j++;
            }

            while (i < n && j < m && nums1[i] <= nums2[j])
                j++;

            ret = max(ret, j - 1 - i);
        }

        return ret;
    }
};