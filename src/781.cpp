#include "../include.h"

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int r = 0;
        map<int, int> mp;

        for (int a : answers)
            mp[a]++;

        for (auto& [k, v] : mp) {
            int group = k + 1;
            r += (v / group + (v % group != 0)) * group;
        }

        return r;
    }
};