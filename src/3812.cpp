#include "../include.h"

class Solution {
public:
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        if (start == target)
            return {};

        vector<vector<pair<int, int>>> tree(n); // (node, index)
        vector<int> deg(n, 0);

        for (int i = 0; i < n - 1; i++) {
            int u = edges[i][0], v = edges[i][1];

            tree[u].push_back({v, i});
            tree[v].push_back({u, i});

            deg[u]++;
            deg[v]++;
        }

        queue<int> q;
        int discrepancies = 0;

        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) {
                q.push(i);
            }

            discrepancies += start[i] != target[i];
        }

        if (discrepancies % 2)
            return {-1};

        vector<int> ret;
        unordered_set<int> must_correct;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            deg[u]--;

            for (auto [v, idx] : tree[u]) {
                if (deg[v] == 0)
                    continue;

                if (start[u] != target[u]) {
                    start[u] = target[u];
                    start[v] = (start[v] == '0' ? '1' : '0');

                    ret.push_back(idx);
                }

                deg[v]--;

                if (deg[v] == 1) {
                    q.push(v);
                }
            }
        }

        sort(ret.begin(), ret.end());

        return ret;
    }
};