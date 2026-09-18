#include "../include.h"

class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& connections, int& bomb_count) {
        for (int neigh : connections[node]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                bomb_count++;
                dfs(neigh, visited, connections, bomb_count);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        const int n = bombs.size();

        vector<vector<int>> connections(n);

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                auto d = (long long)(bombs[i][0] - bombs[j][0]) * (bombs[i][0] - bombs[j][0]) + (long long)(bombs[i][1] - bombs[j][1]) * (bombs[i][1] - bombs[j][1]);
                auto r1 = (long long) bombs[i][2] * bombs[i][2];
                auto r2 = (long long) bombs[j][2] * bombs[j][2];

                if (d <= r1) {
                    connections[i].push_back(j);
                }
                if (d <= r2) {
                    connections[j].push_back(i);
                }
            }
        }

        int ret = 0;

        // Note: this is O(N * E) = O(N^3), because im too lazy for proper union find and merge operations
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            int bomb_count = 1;
            visited[i] = true;

            dfs(i, visited, connections, bomb_count);

            ret = max(ret, bomb_count);
        }

        return ret;
    }
};