#include "../include.h"

class Solution {
public:
    // TODO: O(1) memory
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        unordered_map<int, int> mp;
        const int k = nums.size() / 3 + 1;

        for (int n : nums)
            if (++mp[n] == k)
                ret.push_back(n);

        return ret;
    }
};