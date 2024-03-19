#include "../include.h"

class Solution {
public:
    vector<vector<int>> ret;
    int n;

    void dfs(const vector<vector<int>>& graph, vector<int>& curr, int node) {
        if (node == n - 1) {
            ret.push_back(curr);
            return;
        }

        for (int x : graph[node]) {
            curr.push_back(x);
            dfs(graph, curr, x);
            curr.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(const vector<vector<int>>& graph) {
        vector<int> curr {0};
        n = graph.size();
        dfs(graph, curr, 0);

        return ret;
    }
};