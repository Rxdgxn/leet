#include "../include.h"

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> free_windows;
        const int meetings_count = startTime.size();

        if (startTime[0] != 0)
            free_windows.push_back(startTime[0]);

        for (int i = 1; i < meetings_count; i++)
            free_windows.push_back(startTime[i] - endTime[i - 1]);

        if (eventTime - endTime[meetings_count - 1] != 0)
            free_windows.push_back(eventTime - endTime[meetings_count - 1]);

        const int windows_count = free_windows.size();
        vector<int> dp(windows_count);
        dp[0] = free_windows[0];

        for (int i = 1; i < windows_count; i++)
            dp[i] = dp[i - 1] + free_windows[i];

        if (windows_count <= k + 1)
            return dp.back();

        int ret = dp[k];

        for (int i = k + 1; i < windows_count; i++)
            ret = max(ret, dp[i] - dp[i - k - 1]);

        return ret;
    }
};