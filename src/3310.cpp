#include "../include.h"

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);

        for (auto& edge : invocations) {
            graph[edge[0]].push_back(edge[1]);
        }

        queue<int> q;
        vector<bool> suspicious(n, false);

        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neigh : graph[node]) {
                if (!suspicious[neigh]) {
                    suspicious[neigh] = true;
                    q.push(neigh);
                }
            }
        }

        bool keep_all = false;

        for (auto& edge : invocations) {
            if (!suspicious[edge[0]] && suspicious[edge[1]]) {
                keep_all = true;
                break;
            }
        }

        vector<int> ret;

        if (keep_all) {
            for (int i = 0; i < n; i++)
                ret.push_back(i);

            return ret;
        }

        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};