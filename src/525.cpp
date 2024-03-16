#include "../include.h"

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;

        int z = 0, o = 0, ret = 0;
        const int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i]) o++;
            else z++;

            const int d = z - o;

            if (mp.count(d)) ret = max(ret, i - mp[d]);
            else mp[d] = i;
        }

        return ret;
    }
};