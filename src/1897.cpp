#include "../include.h"

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> apps;
        const int sz = words.size();

        for (int i = 0; i < sz; i++)
            for (char c : words[i]) apps[c]++;

        for (auto& [_k, v] : apps)
            if (v % sz != 0) return false; 

        return true;
    }
};