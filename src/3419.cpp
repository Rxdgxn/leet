#include "../include.h"

class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> graph;
    int total_nodes;

    bool bfs(int max_w) {
        queue<int> q;
        vector<int> vis(total_nodes, 0);

        q.push(0);
        vis[0] = 1;

        int c = 0;

        while (!q.empty()) {
            int t = q.front();
            q.pop();

            c++;

            for (auto [neigh, w] : graph[t]) {
                if (w <= max_w && !vis[neigh]) {
                    q.push(neigh);
                    vis[neigh] = 1;
                }
            }
        }

        if (c != total_nodes)
            return false;

        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        total_nodes = n;

        for (auto& e : edges)
            graph[e[1]].push_back({e[0], e[2]});

        int l = 1, r = 1e6 + 1;
        int ret;

        if (!bfs(r))
            return -1;

        while (l <= r) {
            int m = (l + r) / 2;

            if (bfs(m)) {
                r = m - 1;
                ret = m;
            }
            else {
                l = m + 1;
            }
        }

        return ret;
    }
};