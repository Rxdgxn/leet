#include "../include.h"

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        ios::sync_with_stdio(false);
        cin.tie();

        colors += '.';

        const int n = colors.size();
        int r = 0;

        char u = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++) {
            if (colors[i] == u) {
                pq.push(neededTime[i]);
            }
            else {
                while (pq.size() > 1) {
                    r += pq.top();
                    pq.pop();
                }

                if (!pq.empty()) pq.pop();

                if (i != n - 1) pq.push(neededTime[i]);
            }

            u = colors[i];
        }

        return r;
    }
};