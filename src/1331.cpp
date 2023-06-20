#include "../include.h"

int find(const vector<int>& v, int x) {
    int l = 0, r = v.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (v[m] == x) return m;
        else if (v[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ret;
        unordered_set<int> tmp(arr.begin(), arr.end());
        vector<int> nondups(tmp.begin(), tmp.end());

        sort(nondups.begin(), nondups.end());

        for (int x : arr)
            ret.push_back(find(nondups, x) + 1);

        return ret;
    }
};