#include "../include.h"

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        vector<int> ret;

        for (int i = 0; i < n - 1; i++)
            graph[i].push_back(i + 1);

        for (const auto& query : queries) {
            graph[query[0]].push_back(query[1]);

            queue<pair<int, int>> q;
            q.push({0, 0});

            int min_dist = INT_MAX;

            vector<bool> visited(n, false);
            visited[0] = true;

            while (!q.empty()) {
                auto p = q.front();
                q.pop();

                if (p.first == n - 1) {
                    min_dist = min(min_dist, p.second);
                    break;
                }

                for (int node : graph[p.first]) {
                    if (!visited[node]) {
                        visited[node] = true;
                        q.push({node, p.second + 1});
                    }
                }
            }

            ret.push_back(min_dist);
        }

        return ret;
    }
};