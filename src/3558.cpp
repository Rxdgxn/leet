#include "../include.h"

class Solution {
public:
    const int MOD = 1e9 + 7;

    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int n = edges.size() + 1; // n nodes
        vector<vector<int>> tree(n + 1);

        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        queue<int> q;
        q.push(1);
        
        int max_depth = -1;

        vector<bool> visited(n + 1, false);
        visited[1] = true;

        while (!q.empty()) {
            max_depth++;
            int sz = q.size();

            while (sz--) {
                int node = q.front();
                q.pop();

                for (int neigh : tree[node]) {
                    if (!visited[neigh]) {
                        visited[neigh] = true;
                        q.push(neigh);
                    }
                }
            }
        }

        // C(d, 1) + C(d, 3) + C(d, 5) + ... = 2^(d - 1), d = max_depth

        long long ways = 1;

        for (int i = 0; i < max_depth - 1; i++)
            ways = (ways << 1) % MOD;

        return (int) ways;
    }
};