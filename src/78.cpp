#include "../include.h"

class Solution {
public:
    void generate(vector<vector<int>>& ret, vector<int> set, int i, int n, vector<int>& nums) {
        ret.push_back(set);

        for (int it = i; it < n; it++) {
            set.push_back(nums[it]);
            generate(ret, set, it + 1, n, nums);
            set.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;

        generate(ret, {}, 0, nums.size(), nums);

        return ret;
    }
};