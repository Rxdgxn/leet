#include "../include.h"

class Solution {
public:
    void helper(vector<vector<int>>& ret, vector<int>& curr, vector<int>& candidates, int i, int target) {
        if (target <= 0) {
            if (target == 0) ret.push_back(curr);
            return;
        }

        for (int it = i; it < candidates.size(); it++) {
            if (target >= candidates[it] && (it == i || candidates[it] != candidates[it - 1])) {
                curr.push_back(candidates[it]);
                helper(ret, curr, candidates, it + 1, target - candidates[it]);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ret;
        vector<int> curr;

        helper(ret, curr, candidates, 0, target);

        return ret;
    }
};