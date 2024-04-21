#include "../include.h"

class Solution {
public:
    void dfs(int n, int target, vector<int>& vis, vector<vector<int>>& graph) {
        for (int node : graph[n]) {
            if (!vis[node]) {
                vis[node] = 1;
                dfs(node, target, vis, graph);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (n == 1) return true;

        vector<vector<int>> graph(n);

        for (auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, 0);
        dfs(source, destination, vis, graph);

        return vis[destination];
    }
};