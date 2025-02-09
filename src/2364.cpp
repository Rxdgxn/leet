#include "../include.h"

class Solution {
public:
    typedef long long ll;

    long long countBadPairs(vector<int>& nums) {
        const ll n = nums.size();
        const ll total = (n * (n - 1)) / 2;
        ll good_pairs = 0;

        unordered_map<ll, ll> diffs;
        
        for (int i = 0; i < n; i++)
            diffs[nums[i] - i]++;

        for (auto& [_k, v] : diffs)
            good_pairs += (v * (v - 1)) / 2;
        
        return total - good_pairs;
    }
};