#include "../include.h"

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    int ret = 1;

    int dfs(int node, const string& s) {
        if (graph[node].empty())
            return 1;

        priority_queue<int> longest_child_paths; // a bit overkill

        for (int child : graph[node]) {
            int lp = dfs(child, s);

            if (s[child] != s[node])
                longest_child_paths.push(lp);
        }

        int longest_path = 1;
        int k = 2;

        int top = (longest_child_paths.empty() ? 0 : longest_child_paths.top());

        while (!longest_child_paths.empty() && k--) {
            longest_path += longest_child_paths.top();
            longest_child_paths.pop();
        }

        ret = max(ret, longest_path);

        return 1 + top;
    }

    int longestPath(vector<int>& parent, string s) {
        const int n = parent.size();

        for (int i = 0; i < n; i++)
            graph[parent[i]].push_back(i);

        dfs(0, s);

        return ret;
    }
};