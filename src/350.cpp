#include "../include.h"

class Solution {
public:
    int m1[1001], m2[1001];

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        for (int n : nums1) m1[n]++;

        for (int n : nums2)
            if (m1[n]) m2[n]++;

        vector<int> ret;

        for (int i = 0; i <= 1000; i++)
            if (m2[i])
                for (int j = 0; j < min(m1[i], m2[i]); j++)
                    ret.push_back(i);

        return ret;
    }
};