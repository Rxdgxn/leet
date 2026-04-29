#include "../include.h"

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // dp[i] = costul optim pana in ziua i
        int dp[366] = {0};

        int i = 0;
        for (int day = 1; day <= days.back(); day++) {
            if (day < days[i]) {
                dp[day] = dp[day - 1];
            }
            else {
                i++;
                
                int optimal = dp[day - 1] + costs[0];
                optimal = min(optimal, dp[max(0, day - 7)] + costs[1]);
                optimal = min(optimal, dp[max(0, day - 30)] + costs[2]);

                dp[day] = optimal;
            }
        }

        return dp[days.back()];
    }
};