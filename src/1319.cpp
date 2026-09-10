#include "../include.h"

class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& already_in_component) {
        already_in_component[node] = true;

        for (int neigh : graph[node]) {
            if (!already_in_component[neigh]) {
                dfs(neigh, graph, already_in_component);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        vector<vector<int>> graph(n);
        vector<bool> already_in_component(n, false);

        for (auto& e : connections) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!already_in_component[i]) {
                components++;
                dfs(i, graph, already_in_component);
            }
        }

        return components - 1;
    }
};