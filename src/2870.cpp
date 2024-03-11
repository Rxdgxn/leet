#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int n : nums) mp[n]++;

        int ops = 0;

        for (auto& [_, v] : mp) {
            if (v == 1) return -1;

            ops = ops + v / 3 + (v % 3 != 0);
        }

        return ops;
    }
};