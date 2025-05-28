#include "../include.h"

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // find nodes with most target nodes in range k - 1 for second graph; range k for first graph
        unordered_map<int, vector<int>> graph1, graph2;

        for (auto& e : edges1) {
            graph1[e[0]].push_back(e[1]);
            graph1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            graph2[e[0]].push_back(e[1]);
            graph2[e[1]].push_back(e[0]);
        }

        const int n = graph1.size(), m = graph2.size();

        int max_targets = 0;
        for (int i = 0; i < m && k > 0; i++) {
            int visited[1000] = {0};
            queue<pair<int, int>> q; // (node, range)

            q.push({i, 0});

            int targets = 0;

            while (!q.empty()) {
                auto p = q.front();
                q.pop();

                targets++;
                visited[p.first] = 1;

                for (int adj : graph2[p.first]) {
                    if (!visited[adj] && p.second < k - 1) {
                        q.push({adj, p.second + 1});
                    }
                }
            }

            max_targets = max(max_targets, targets);
        }

        vector<int> ret(n);
        for (int i = 0; i < n; i++) {
            int visited[1000] = {0};
            queue<pair<int, int>> q; // (node, range)

            q.push({i, 0});

            int targets = 0;

            while (!q.empty()) {
                auto p = q.front();
                q.pop();

                targets++;
                visited[p.first] = 1;

                for (int adj : graph1[p.first]) {
                    if (!visited[adj] && p.second < k) {
                        q.push({adj, p.second + 1});
                    }
                }
            }

            ret[i] = targets + max_targets;
        }

        return ret;
    }
};