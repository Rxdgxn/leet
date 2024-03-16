#include "../include.h"

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> mp;
        vector<int> ret(k);

        for (auto& log : logs)
            mp[log[0]].insert(log[1]);
        
        for (auto& it : mp)
            ret[it.second.size() - 1]++;

        return ret;
    }
};