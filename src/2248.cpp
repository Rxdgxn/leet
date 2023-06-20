#include "../include.h"

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> inter;
        vector<int> ret;

        for (auto v : nums) {
            for (int x : v) {
                inter[x]++;
            }
        }
        for (auto it = inter.begin(); it != inter.end(); it++) {
            if (it->second == nums.size()) ret.push_back(it->first);
        }

        return ret;
    }
};