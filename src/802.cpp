#include "../include.h"

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& inStack, vector<bool>& vis) {
        if (inStack[node]) return true;
        if (vis[node]) return false;

        inStack[node] = true;
        vis[node] = true;

        for (int neighbor : graph[node])
            if (dfs(neighbor, graph, inStack, vis))
                return true;

        inStack[node] = false;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int n = graph.size();

        vector<bool> inStack(n), vis(n);

        for (int node = 0; node < n; node++)
            dfs(node, graph, inStack, vis);

        vector<int> nodes;

        for (int node = 0; node < n; node++)
            if (!inStack[node]) nodes.push_back(node);

        return nodes;
    }
};