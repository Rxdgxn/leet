#include "../include.h"

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        const int sz = names.size();
        map<int, string> hs;

        for (int i = 0; i < sz; i++)
            hs[heights[i]] = names[i];
        
        names = {};
        for (auto it = hs.rbegin(); it != hs.rend(); it++)
            names.push_back(it->second);

        return names;
    }
};