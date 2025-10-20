#include "../include.h"

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [&](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] < b[1];

            return a[0] > b[0];
        });

        vector<vector<int>> ret;

        for (auto& p : people)
            ret.insert(ret.begin() + p[1], p);

        return ret;
    }
};