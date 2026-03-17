#include "../include.h"

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();

        int ret = 0;

        vector<int> dp(n); // dp[i] = last consecutive ones per column i

        for (int j = 0; j < n; j++) {
            dp[j] = matrix[0][j];

            // initial matrix will be just a row of ones (if there are any)
            if (dp[j])
                ret++;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (matrix[i][j])
                    dp[j]++;
                else
                    dp[j] = 0;

            priority_queue<int> sorted(dp.begin(), dp.end());

            int width = 0;

            while (!sorted.empty() && sorted.top() > 0) {
                width++;

                // we'll have a minimum "height" (of consecutive ones) inferred by the top of the pq
                ret = max(ret, width * sorted.top());

                sorted.pop();
            }
        }

        return ret;
    }
};