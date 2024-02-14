#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        const int sz = nums.size();
        vector<int> p(sz / 2), n(sz / 2);
        
        int ip = 0, in = 0;

        for (int i = 0; i < sz; i++)
            if (nums[i] > 0) p[ip++] = nums[i];
            else n[in++] = nums[i];

        ip = 0, in = 0;
        
        for (int i = 0; i < sz; i++)
            if (i % 2 == 0) nums[i] = p[ip++];
            else nums[i] = n[in++];
        
        return nums;
    }
};