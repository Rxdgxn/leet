#include "../include.h"

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        // for each component, calc the AND of all weights
        vector<unordered_set<int>> components;
        unordered_map<int, unordered_set<int>> graph;
        unordered_map<int, int> overall_weight, node_to_component, component_weight;

        for (auto& e : edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);

            if (overall_weight.find(e[0]) == overall_weight.end())
                overall_weight.insert({e[0], e[2]});
            else
                overall_weight[e[0]] &= e[2];

            if (overall_weight.find(e[1]) == overall_weight.end())
                overall_weight.insert({e[1], e[2]});
            else
                overall_weight[e[1]] &= e[2];
        }

        vector<int> visited(n, 0);
        for (int node = 0; node < n; node++) {
            if (visited[node])
                continue;

            queue<int> q;
            unordered_set<int> comp;

            q.push(node);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                if (visited[node])
                    continue;

                visited[node] = 1;
                comp.insert(node);
                node_to_component[node] = components.size();

                for (int neigh : graph[node])
                    q.push(neigh);
            }

            int w = overall_weight[*comp.begin()];
            for (int node : comp)
                w &= overall_weight[node];

            component_weight[components.size()] = w;
            components.push_back(comp);
        }

        vector<int> ret(query.size());

        for (int i = 0; i < query.size(); i++) {
            if (node_to_component[query[i][0]] != node_to_component[query[i][1]])
                ret[i] = -1;
            else
                ret[i] = component_weight[node_to_component[query[i][0]]];
        }

        return ret;
    }
};