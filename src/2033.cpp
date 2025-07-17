#include "../include.h"

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> input;
        unordered_set<int> rems;

        for (auto& v : grid) {
            for (int y : v) {
                input.push_back(y);
                rems.insert(y % x);
            }
        }

        if (rems.size() > 1)
            return -1;

        sort(input.begin(), input.end());

        int med = input[input.size() / 2];
        int ret = 0;

        for (int n : input)
            ret += abs(n - med) / x;

        return ret;
    }
};