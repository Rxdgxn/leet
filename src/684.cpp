#include "../include.h"

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    int repeated_node = 0;

    void dfs(int node, int prev_node, unordered_set<int>& visited, vector<int>& current_path) {
        if (visited.find(node) != visited.end()) {
            repeated_node = node;
            return;
        }

        if (repeated_node > 0)
            return;

        for (int neigh : graph[node]) {
            if (neigh != prev_node) {
                visited.insert(node);
                current_path.push_back(node);
                dfs(neigh, node, visited, current_path);

                if (repeated_node > 0)
                    return;

                visited.erase(node);
                current_path.pop_back();
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        vector<int> path;

        dfs(1, 1, visited, path);

        unordered_set<int> cycle;

        // Only actually add the cycle nodes
        int i;
        for (i = 0; i < path.size() && path[i] != repeated_node; i++);

        for (int j = i; j < path.size(); j++)
            cycle.insert(path[j]);

        for (auto it = edges.rbegin(); it != edges.rend(); it++)
            if (cycle.find((*it)[0]) != cycle.end() && cycle.find((*it)[1]) != cycle.end())
                return *it;

        return {};
    }
};