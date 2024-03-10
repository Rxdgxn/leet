#include "../include.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int mp[1001] = {0};
        vector<int> ret;

        for (int n : nums1)
            mp[n] = 1;
        
        for (int n : nums2)
            if (mp[n] == 1) mp[n] = 2;

        for (int i = 0; i <= 1000; i++)
            if (mp[i] == 2) ret.push_back(i);

        return ret;
    }
};