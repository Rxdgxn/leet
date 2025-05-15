#include "../include.h"

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ret;
        int prev_added = groups[0];
        ret.push_back(words[0]);

        const int n = groups.size();

        for (int i = 1; i < n; i++) {
            if (groups[i] != prev_added) {
                ret.push_back(words[i]);
                prev_added = groups[i];
            }
        }

        return ret;
    }
};