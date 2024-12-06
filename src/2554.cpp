#include "../include.h"

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> set(banned.begin(), banned.end());

        int ret = 0, s = 0;

        for (int i = 1; i <= n && s + i <= maxSum; i++) {
            if (set.find(i) == set.end()) {
                s += i;
                ret++;
            }
        }

        return ret;
    }
};