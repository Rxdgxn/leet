#include "../include.h"

class Solution {
public:
    int road_from_to[100][100];

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<unordered_set<int>> graph(n);
        vector<bool> ret;

        for (auto& edge : edges)
            graph[edge[0]].insert(edge[1]);

        for (int i = 0; i < n; i++) {
            queue<int> q;
            int vis[100] = {0};

            q.push(i);
            vis[i] = 1;

            while (!q.empty()) {
                int t = q.front();
                q.pop();

                for (int node : graph[t]) {
                    if (!vis[node]) {
                        vis[node] = 1;

                        road_from_to[i][node] = 1;
                        q.push(node);
                    }
                }
            }
        }

        for (auto& q : queries)
            ret.push_back(road_from_to[q[0]][q[1]]);

        return ret;
    }
};