#include "../include.h"

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        const int n = patience.size();

        vector<int> dist(n, INT_MAX);
        vector<vector<int>> graph(n);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        queue<int> q;
        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neigh : graph[node]) {
                if (dist[neigh] == INT_MAX) {
                    dist[neigh] = dist[node] + 1;
                    q.push(neigh);
                }
            }
        }

        int ret = 0;

        for (int node = 1; node < n; node++) {
            dist[node] <<= 1;

            int extra = (dist[node] - 1) / patience[node];
            int last_second = extra * patience[node];

            ret = max(ret, last_second + dist[node]);
        }

        return ret + 1;
    }
};