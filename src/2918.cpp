#include "../include.h"

// Obviously, stolen :)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long z1 = 0, z2 = 0, s1 = 0, s2 = 0;

        for (int it : nums1) {
            s1 += max(it, 1);
            z1 += (it == 0);
        }
        for (int it : nums2) {
            s2 += max(it, 1);
            z2 += (it == 0);
        }

        if (s1 < s2 && z1 == 0 || s1 > s2 && z2 == 0) return -1;

        return max(s1, s2);
    }
};