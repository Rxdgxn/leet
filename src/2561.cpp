#include "../include.h"

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        int mn = INT_MAX;

        for (int f : basket1) {
            freq[f]++;
            mn = min(mn, f);
        }
        for (int f : basket2) {
            freq[f]--;
            mn = min(mn, f);
        }

        vector<int> merge;
        
        for (auto [k, v] : freq) {
            if (v % 2 != 0)
                return -1;

            for (int i = 0; i < abs(v) / 2; i++)
                merge.push_back(k);
        }

        sort(merge.begin(), merge.end());

        long long ret = 0;

        for (int i = 0; i < merge.size() / 2; i++)
            ret += min(2 * mn, merge[i]);

        return ret;
    }
};