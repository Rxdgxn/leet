#include "include.h"

class Solution {
public:

    #define ADD(s) for (int i = (s); i < sz; i += 2) {\
                    ret[i] = unsorted[k].first;\
                    unsorted[k].second--;\
                    if (!unsorted[k].second) k++;\
                }\

    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }

    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int sz = barcodes.size();
        unordered_map<int, int> priority;
        vector<int> ret(sz);
        vector<pair<int, int>> unsorted;

        for (int code : barcodes) priority[code]++;
        for (auto it = priority.begin(); it != priority.end(); it++) {
            unsorted.push_back(make_pair(it->first, it->second));
        }
        sort(unsorted.begin(), unsorted.end(), cmp);

        int k = 0;
        ADD(0);
        ADD(1);

        return ret;
    }
};