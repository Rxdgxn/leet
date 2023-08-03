#include "../include.h"

class Solution {
public:
    unordered_map<int, int> freq;

    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        vector<pair<int, int>> u;
        
        for (int n : nums) freq[n]++;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            u.push_back(make_pair(it->first, it->second));
        }
        sort(u.begin(), u.end(), cmp);

        for (int i = 0; i < k; i++) ret.push_back(u[i].first);

        return ret;
    }
};