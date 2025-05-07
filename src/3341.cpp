#include "../include.h"

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        auto cmp = [&](vector<int>& a, vector<int>& b) {
            return a[2] > b[2];
        };

        // Thanks leetcode for using a priority queue + decltype info
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp); // (row, col, time);

        q.push({0, 0, 0});
        dp[0][0] = 0;

        while (!q.empty()) {
            auto v = q.top();
            q.pop();

            if (vis[v[0]][v[1]]) continue;
            vis[v[0]][v[1]] = 1;

            dp[v[0]][v[1]] = min(dp[v[0]][v[1]], v[2]);

            if (v[0] + 1 < n && 1 + max(dp[v[0]][v[1]], moveTime[v[0] + 1][v[1]]) < dp[v[0] + 1][v[1]])
                q.push({v[0] + 1, v[1], 1 + max(dp[v[0]][v[1]], moveTime[v[0] + 1][v[1]])});

            if (v[1] + 1 < m && 1 + max(dp[v[0]][v[1]], moveTime[v[0]][v[1] + 1]) < dp[v[0]][v[1] + 1])
                q.push({v[0], v[1] + 1, 1 + max(dp[v[0]][v[1]], moveTime[v[0]][v[1] + 1])});

            if (v[0] - 1 >= 0 && 1 + max(dp[v[0]][v[1]], moveTime[v[0] - 1][v[1]]) < dp[v[0] - 1][v[1]])
                q.push({v[0] - 1, v[1], 1 + max(dp[v[0]][v[1]], moveTime[v[0] - 1][v[1]])});

            if (v[1] - 1 >= 0 && 1 + max(dp[v[0]][v[1]], moveTime[v[0]][v[1] - 1]) < dp[v[0]][v[1] - 1])
                q.push({v[0], v[1] - 1, 1 + max(dp[v[0]][v[1]], moveTime[v[0]][v[1] - 1])});
        }

        return dp[n - 1][m - 1];
    }
};