#include "../include.h"

// Same for 3741
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> occ;
        int ret = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            auto& positions = occ[nums[i]];
            positions.push_back(i);
            
            const int len = positions.size();

            if (len > 2)
                ret = min(ret, positions[len - 1] - positions[len - 3]); // formula can be reduced for i < j < k
        }

        if (ret == INT_MAX)
            return -1;

        return ret * 2; // we only multiply at the end (micro-optimization)
    }
};