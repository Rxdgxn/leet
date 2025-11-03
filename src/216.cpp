#include "../include.h"

class Solution {
public:
    vector<vector<int>> ret;

    void back(set<int>& used, int i, int target, int k) {
        if (target < 0) {
            return;
        }

        if (target == 0 && k == 0) {
            vector<int> tmp;

            for (int x : used)
                tmp.push_back(x);

            ret.push_back(tmp);
            return;
        }

        if (target > 0 && k == 0) {
            return;
        }

        for (int j = i + 1; j <= 9; j++) {
            used.insert(j);
            back(used, j, target - j, k - 1);
            used.erase(j);
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        set<int> used;

        for (int i = 1; i <= 9; i++) {
            used.insert(i);
            back(used, i, n - i, k - 1);
            used.erase(i);
        }

        return ret;
    }
};