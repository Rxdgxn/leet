#include "../include.h"

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> index;
        const int n = nums.size();
        vector<int> ret(n);

        for (int i = 0; i < n; i++)
            index.insert({nums[i], i});

        for (const auto& op : operations) {
            int i = index[op[0]];
            index.erase(op[0]);
            index.insert({op[1], i});
        }

        for (auto [k, v] : index)
            ret[v] = k;

        return ret;
    }
};