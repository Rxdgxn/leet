#include "../include.h"

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, vector<pair<int, int>>> graph;
        vector<int> vis(n + 1, 0);

        for (auto& t : times)
            graph[t[0]].push_back({t[1], t[2]});

        pq.push({0, k});
        int time = 0, acs = 0;

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            if (vis[p.second])
                continue;

            vis[p.second] = 1;
            time = max(time, p.first);
            acs++;

            for (auto& px : graph[p.second])
                pq.push({p.first + px.second, px.first});
        }

        if (acs < n)
            return -1;

        return time;
    }
};