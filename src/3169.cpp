#include "../include.h"

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        const int n = meetings.size();
        int ret = meetings[0][0] - 1;

        int end = meetings[0][1];

        for (int i = 1; i < n; i++) {
            if (meetings[i][0] <= end) {
                end = max(end, meetings[i][1]);
                continue;
            }

            ret += meetings[i][0] - end - 1;
            end = meetings[i][1];
        }

        ret += days - end;

        return ret;
    }
};