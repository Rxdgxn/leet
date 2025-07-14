#include "../include.h"

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        const int n = startTime.size();
        int it = 0;
        
        priority_queue<int> gaps;
        vector<int> total_windows(2 * n + 1); // both gaps and meetings

        gaps.push(startTime[0]);
        total_windows[it++] = startTime[0];

        for (int i = 1; i < n; i++) {
            total_windows[it++] = endTime[i - 1] - startTime[i - 1];
            total_windows[it++] = startTime[i] - endTime[i - 1];
            gaps.push(startTime[i] - endTime[i - 1]);
        }

        total_windows[it++] = endTime[n - 1] - startTime[n - 1];
        total_windows[it++] = eventTime - endTime[n - 1];
        gaps.push(eventTime - endTime[n - 1]);

        int ret = 0;

        for (int i = 0; i < it - 2; i += 2) {
            ret = max(ret, total_windows[i] + total_windows[i + 2]);

            // Ignore the two gaps to the left and right of a meeting
            vector<int> place_back;

            if (gaps.top() == max(total_windows[i], total_windows[i + 2])) {
                place_back.push_back(gaps.top());
                gaps.pop();

                if (gaps.top() == min(total_windows[i], total_windows[i + 2])) {
                    place_back.push_back(gaps.top());
                    gaps.pop();
                }
            }

            // We can move the meeting to some gap
            if (gaps.top() >= total_windows[i + 1])
                ret = max(ret, total_windows[i] + total_windows[i + 1] + total_windows[i + 2]);

            for (int gap : place_back)
                gaps.push(gap);
        }

        return ret;
    }
};