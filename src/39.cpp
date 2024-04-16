#include "include.h"

class Solution {
public:
    vector<vector<int>> ret;

    void bkt(vector<int>& candidates, int target, int i, vector<int>& curr) {
        if (target == 0) {
            ret.push_back(curr);
            return;
        }

        if (target < candidates[i]) return;

        for (int j = i; j < candidates.size(); j++) {
            curr.push_back(candidates[j]);
            bkt(candidates, target - candidates[j], j, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;

        bkt(candidates, target, 0, curr);

        return ret;
    }
};