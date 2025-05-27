#include "../include.h"

class Solution {
public:
    unordered_map<int, int> marked;
    unordered_map<int, vector<int>> graph;
    int col_val = 0;

    void dfs(int node, const string& colors, bool& cycle, vector<vector<int>>& cc) {
        if (marked[node] == -1) {
            cycle = true;
            return;
        }
        if (marked[node] == 1)
            return;

        marked[node] = -1;

        for (int adj : graph[node]) {
            dfs(adj, colors, cycle, cc);

            for (int i = 0; i < 26; i++)
                cc[node][i] = max(cc[node][i], cc[adj][i]);
        }

        marked[node] = 1;
        cc[node][colors[node] - 'a']++;
        col_val = max(col_val, cc[node][colors[node] - 'a']);
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        for (auto& e : edges)
            graph[e[0]].push_back(e[1]);

        const int n = colors.size();
        vector<vector<int>> colors_count(n, vector<int>(26, 0));

        for (int i = 0; i < n; i++) {
            if (!marked[i]) {
                bool cycle = false;
                dfs(i, colors, cycle, colors_count);

                if (cycle)
                    return -1;
            }
        }

        return col_val;
    }
};