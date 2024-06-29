#include "../include.h"

class Solution {
public:
    void dfs(int ancestor, int node, vector<vector<int>>& graph, vector<vector<int>>& ancestors) {
        for (int n : graph[node]) {
            if (ancestors[n].empty() || ancestors[n].back() != ancestor) {
                ancestors[n].push_back(ancestor);
                dfs(ancestor, n, graph, ancestors);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n), ancestors(n);
        vector<set<int>> ret(n);

        for (auto& edge : edges)
            graph[edge[0]].push_back(edge[1]);
        
        for (int node = 0; node < n; node++)
            dfs(node, node, graph, ancestors);

        return ancestors;
    }
};