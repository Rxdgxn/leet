#include "../include.h"

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>> q;

        const int n = tickets.size();
        for (int i = 0; i < n; i++)
            q.push({i, tickets[i]});

        int t = 0;

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            if (p.second > 1) q.push({p.first, p.second - 1});
            
            if (p.first == k && p.second == 1) return t + 1;
            
            t++;
        }

        return -1;
    }
};