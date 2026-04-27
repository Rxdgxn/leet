#include "../include.h"

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    int visit_time = 0;

    int dfs(int node, int parent, const vector<bool>& hasApple) {
        int apples = hasApple[node];

        for (int child : graph[node]) {
            if (child == parent)
                continue;

            visit_time++;

            int child_apples = dfs(child, node, hasApple);
            apples += child_apples;

            if (child_apples > 0)
                visit_time++;
            else
                visit_time--;
        }

        return apples;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        dfs(0, -1, hasApple);

        return visit_time;
    }
};