#include "../include.h"

class Solution {
public:
    typedef vector<vector<int>> Graph;
    int edges_changed = 0;

    void dfs(const Graph& g, int node, vector<bool>& visited, const vector<vector<int>>& dirs) {
        visited[node] = true;

        for (int n : g[node]) {
            if (!visited[n]) {
                for (int d : dirs[node]) {
                    if (d == n) edges_changed++;
                }
                
                dfs(g, n, visited, dirs);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        Graph graph(n);
        vector<vector<int>> dirs(n);

        for (auto& c : connections) {
            dirs[c[0]].push_back(c[1]);

            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }

        vector<bool> visited(n, false);
        dfs(graph, 0, visited, dirs);

        return edges_changed;
    }
};