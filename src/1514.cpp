#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    double prob = 0;

    void dfs(vector<vector<pair<int, double>>>& graph, int node, int target, vector<int>& vis, double curr) {
        if (curr <= 1e-5) return;

        if (node == target) {
            prob = max(prob, curr);
            return;
        }

        vis[node] = 1;

        for (auto& p : graph[node]) {
            if (!vis[p.first] && curr * p.second >= prob) {
                dfs(graph, p.first, target, vis, curr * p.second);
            }
        }

        vis[node] = 0;
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);
        vector<int> vis(n, 0);

        const int sz = edges.size();

        for (int i = 0; i < sz; i++) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        dfs(graph, start_node, end_node, vis, 1);

        return prob;
    }
};