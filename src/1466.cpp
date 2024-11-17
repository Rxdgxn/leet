#include "../include.h"

class Solution {
public:
    enum Direction {
        IN,
        OUT
    };

    typedef vector<vector<pair<int, Direction>>> Graph;
    int edges_changed = 0;

    void dfs(const Graph& g, int node, vector<bool>& visited) {
        visited[node] = true;

        for (auto& p : g[node]) {
            if (!visited[p.first]) {
                if (p.second == OUT) edges_changed++;
                dfs(g, p.first, visited);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        Graph graph(n);

        for (auto& c : connections) {
            graph[c[0]].push_back({c[1], OUT});
            graph[c[1]].push_back({c[0], IN});
        }

        vector<bool> visited(n, false);
        dfs(graph, 0, visited);

        return edges_changed;
    }
};