#include "../include.h"

class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int>& visited, int node, int& ns, int& es) {
        visited[node] = 1;
        ns++;

        for (int adj : graph[node]) {
            es++;
            if (!visited[adj]) dfs(graph, visited, adj, ns, es);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int comps = 0;

        vector<vector<int>> graph(n);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> visited(n, 0);

        for (int node = 0; node < n; node++) {
            int ns = 0, es = 0;
            
            if (!visited[node])
                dfs(graph, visited, node, ns, es);

            if (es == ns * (ns - 1) && ns) comps++;
        }

        return comps;
    }
};