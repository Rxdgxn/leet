#include "../include.h"

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        dist[0][1] = 0;

        vector<vector<pair<int, int>>> graph(n); // (node, weight)

        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 1}); // distance, node, label count

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            if (top[1] == n - 1)
                return top[0];

            for (auto& [neigh, w] : graph[top[1]]) {
                int newCount = (labels[top[1]] == labels[neigh] ? top[2] + 1 : 1);
                if (newCount > k)
                    continue;

                if (top[0] + w < dist[neigh][newCount]) {
                    dist[neigh][newCount] = top[0] + w;
                    pq.push({dist[neigh][newCount], neigh, newCount});
                }
            }
        }

        int ret = INT_MAX;

        for (int i = 1; i <= k; i++)
            ret = min(ret, dist[n - 1][i]);

        if (ret == INT_MAX)
            return -1;

        return ret;
    }
};