#include "../include.h"

class Solution {
public:
    void dfs(int node, vector<vector<pair<int, int>>>& graph, int& output, vector<int>& dist, int ss) {
        for (auto [neigh, w] : graph[node]) {
            if (dist[neigh] == INT_MAX) {
                dist[neigh] = dist[node] + w;

                if (dist[neigh] % ss == 0) {
                    output += 1;
                }

                dfs(neigh, graph, output, dist, ss);
            }
        }
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        const int n = edges.size() + 1;
        vector<vector<pair<int, int>>> graph(n);
        vector<int> ret(n, 0);

        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        for (int root = 0; root < n; root++) {
            if (graph[root].size() == 1) {
                continue;
            }

            vector<int> dist(n, INT_MAX);
            dist[root] = 0;

            vector<int> server_groups;
            for (auto [neigh, w] : graph[root]) {
                dist[neigh] = w;
                int servers = 0;

                if (w % signalSpeed == 0) {
                    servers++;
                }

                dfs(neigh, graph, servers, dist, signalSpeed);

                if (servers > 0) {
                    server_groups.push_back(servers);
                }
            }

            // x1 * x2 + x1 * x3 + ... + x1 * xn + x2 * x3 + x2 * x4 + ...
            const int sz = server_groups.size();
            if (sz > 1) {
                int curr_sum = server_groups[sz - 1];
                
                for (int i = sz - 2; i >= 0; i--) {
                    ret[root] += server_groups[i] * curr_sum;
                    curr_sum += server_groups[i];
                }
            }
        }

        return ret;
    }
};