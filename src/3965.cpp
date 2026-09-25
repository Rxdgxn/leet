#include "../include.h"

class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> tree(n);
        vector<int> degree(n, 0);
        vector<long long> latest(n, 0), earliest(n, LLONG_MAX), finalTime(n);

        for (auto& e : edges) {
            tree[e[1]].push_back(e[0]);
            degree[e[0]]++;
        }

        // Topo sort
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (degree[i] == 0) {
                q.push(i);
                finalTime[i] = baseTime[i];
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neigh : tree[node]) {
                degree[neigh]--;
                latest[neigh] = max(latest[neigh], finalTime[node]);
                earliest[neigh] = min(earliest[neigh], finalTime[node]);

                if (degree[neigh] == 0) {
                    q.push(neigh);
                    finalTime[neigh] = 2 * latest[neigh] - earliest[neigh] + baseTime[neigh];
                }
            }
        }

        return finalTime[0];
    }
};