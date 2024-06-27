#include "../include.h"

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = 0;
        for (auto& e : edges) {
            n = max(n, max(e[0], e[1]));
        }
        
        vector<vector<int>> graph(n + 1);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        for (int i = 1; i <= n; i++)
            if (graph[i].size() == n - 1) return i;

        return -1;
    }
};