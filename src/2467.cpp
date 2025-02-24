#include "../include.h"

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> timeReachedByBob;
    int mx = INT_MIN;

    bool bob_dfs(int node, int time, vector<int>& visited) {
        timeReachedByBob[node] = time;
        visited[node] = 1;

        if (node == 0) return true;

        for (int n : graph[node])
            if (!visited[n] && bob_dfs(n, time + 1, visited))
                return true;

        timeReachedByBob.erase(node);
        return false;
    }

    void alice_dfs(int node, int time, vector<int>& visited, int income, vector<int>& amount) {
        visited[node] = 1;

        if (timeReachedByBob.find(node) == timeReachedByBob.end() || time < timeReachedByBob[node])
            income += amount[node];
        else if (timeReachedByBob[node] == time)
            income += amount[node] / 2;

        if (graph[node].size() == 1 && node != 0)
            mx = max(mx, income);

        for (int n : graph[node])
            if (!visited[n])
                alice_dfs(n, time + 1, visited, income, amount);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(amount.size(), 0);
        bob_dfs(bob, 0, visited);

        visited = vector<int>(amount.size(), 0);
        alice_dfs(0, 0, visited, 0, amount);

        return mx;
    }
};