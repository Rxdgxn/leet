#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n);

        for (auto& road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }

        sort(graph.begin(), graph.end(), [&](vector<int>& a, vector<int>& b) {
            return a.size() > b.size();
        });

        long long s = 0;

        for (int i = 0; i < n; i++)
            s += (graph[i].size() * (n - i));

        return s;
    }
};