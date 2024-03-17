#include "../include.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> ret;

        if (n == 0) return { newInterval };

        while (i < n) {
            if (intervals[i][0] > newInterval[1]) break;
            else if (intervals[i][1] < newInterval[0]) ret.push_back(intervals[i]);
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }

            i++;
        }

        ret.push_back(newInterval);

        while (i < n) ret.push_back(intervals[i++]);

        return ret;
    }
};