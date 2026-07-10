#include "../include.h"

class Solution {
public:
    int global_id = 0;

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp_id(n, 0);

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                comp_id[i] = comp_id[i - 1] + 1;
            }
            else {
                comp_id[i] = comp_id[i - 1];
            }
        }

        int m = queries.size();
        vector<bool> ret(m);

        for (int i = 0; i < m; i++) {
            ret[i] = comp_id[queries[i][0]] == comp_id[queries[i][1]];
        }

        return ret;
    }
};