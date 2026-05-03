#include "../include.h"

class Solution {
public:
    int ts = 0;
    vector<int> low_link, found, parent;
    vector<vector<int>> ret, graph;

    void dfs(int node) {
        found[node] = ts++;
        low_link[node] = found[node];

        for (int neigh : graph[node]) {
            if (found[neigh] != -1) {
                if (parent[node] != neigh) {
                    low_link[node] = min(low_link[node], found[neigh]);
                }
                continue;
            }

            parent[neigh] = node;
            dfs(neigh);
            low_link[node] = min(low_link[node], low_link[neigh]);

            if (low_link[neigh] > found[node]) {
                ret.push_back({node, neigh});
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        low_link = vector<int>(n, -1);
        found = vector<int>(n, -1);
        parent = vector<int>(n, -1);

        graph = vector<vector<int>>(n);

        for (auto& c : connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }

        for (int i = 0; i < n; i++) {
            if (found[i] == -1) {
                parent[i] = i;
                dfs(i);
            }
        }

        return ret;
    }
};