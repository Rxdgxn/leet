#include "../include.h"

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> graph;
        int ret = INT_MAX;
        
        for (auto& r : roads) {
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0], r[2]});
        }

        queue<pair<int, int>> q;
        q.push({1, INT_MAX});

        unordered_set<int> visited;

        while (!q.empty()) {
            auto [node, d] = q.front();
            q.pop();

            visited.insert(node);
            ret = min(ret, d);

            for (auto [next, nd] : graph[node])
                if (visited.find(next) == visited.end())
                    q.push({next, nd});
        }

        return ret;
    }
};