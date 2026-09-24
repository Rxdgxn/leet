#include "../include.h"

class Solution {
public:
    // Note: a better solution would be using Tarjan's CV algorithm
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        const int n = graph.size();
        vector<bool> valid(n, true);
        int minimum_infected = n;

        sort(initial.begin(), initial.end());
        int best_node = initial[0];

        for (int node : initial) {
            valid[node] = false;

            queue<int> q;
            vector<bool> visited(n, false);

            for (int node : initial) {
                if (valid[node]) {
                    visited[node] = true;
                    q.push(node);
                }
            }

            int infected = 0;

            while (!q.empty()) {
                int x = q.front();
                q.pop();
                infected++;

                auto& row = graph[x];

                for (int neigh = 0; neigh < n; neigh++) {
                    if (row[neigh] && !visited[neigh] && valid[neigh]) {
                        visited[neigh] = true;
                        q.push(neigh);
                    }
                }
            }

            if (infected < minimum_infected) {
                minimum_infected = infected;
                best_node = node;
            }

            valid[node] = true;
        }

        return best_node;
    }
};