#include "../include.h"

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> graph(n, 0);
        int x = 0;
        unordered_map<int, set<int>> conn;

        for (const auto& road : roads) {
            graph[road[0]]++;
            graph[road[1]]++;
            conn[road[0]].insert(road[1]);
            conn[road[1]].insert(road[0]);
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int c = conn[i].find(j) != conn[i].end();
                x = max(x, graph[i] + graph[j] - c);
            }
        }

        return x;
    }
};