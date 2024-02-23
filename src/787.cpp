#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (const auto& f : flights)
            graph[f[0]].push_back({f[1], f[2]});

        vector<int> visited(n, INT_MAX);
        visited[src] = 0;

        queue<pair<int, int>> q;
        q.push({src, 0});

        k++;
        while (k--) {
            int sz = q.size();

            while (sz--) {
                auto p = q.front();
                q.pop();

                int cost = p.second;

                for (auto& n : graph[p.first]) {
                    const int x = cost + n.second;
                    if (x < visited[n.first]) {
                        visited[n.first] = x;
                        q.push({n.first, x});
                    }
                }
            }
        }

        if (visited[dst] == INT_MAX) return -1;
        return visited[dst];
    }
};