#include "../include.h"

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> value_by_id;

        for (auto& p : nums1)
            value_by_id[p[0]] += p[1];

        for (auto& p : nums2)
            value_by_id[p[0]] += p[1];

        const int n = value_by_id.size();
        vector<vector<int>> ret(n);

        int it = 0;

        for (auto& [id, val] : value_by_id)
            ret[it++] = {id, val};

        return ret;
    }
};