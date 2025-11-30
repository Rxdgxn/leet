#include "../include.h"

class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> graph; // node -> [(neigh, time)]
    unordered_map<int, int> visited;

    int max_q = 0;

    void dfs(int node, int time, int curr_sum, vector<int>& values, int maxTime) {
        if (node == 0)
            max_q = max(max_q, curr_sum);

        for (auto& p : graph[node]) {
            if (time + p.second > maxTime)
                continue;

            int add = (visited[p.first] == 0 ? values[p.first] : 0);
            
            visited[p.first]++;
            dfs(p.first, time + p.second, curr_sum + add, values, maxTime);
            visited[p.first]--;
        }
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        for (auto& e : edges) {
            graph[e[0]].push_back(make_pair(e[1], e[2]));
            graph[e[1]].push_back(make_pair(e[0], e[2]));
        }

        visited[0] = 1;

        dfs(0, 0, values[0], values, maxTime);

        return max_q;
    }
};