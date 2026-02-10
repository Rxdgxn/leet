#include "../include.h"

class RangeFreqQuery {
public:
    unordered_map<int, set<int>> occ;
    unordered_map<int, unordered_map<int, int>> count_until;
    unordered_map<int, int> count_overall;

    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            occ[arr[i]].insert(i);
            count_until[arr[i]][i] = ++count_overall[arr[i]];
        }
    }
    
    int query(int left, int right, int value) {
        set<int>& indices = occ[value];

        auto first = indices.lower_bound(left);
        auto last = indices.lower_bound(right);

        if (first == indices.end() || *first > right)
            return 0;

        if (last == indices.end() || *last > right)
            right = *prev(last);

        return count_until[value][right] - count_until[value][*first] + 1;
    }
};