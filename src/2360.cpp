#include "../include.h"

class Solution {
public:
    int ret = -1;
    vector<int> length_until;

    void dfs(int node, int l, unordered_set<int>& path, const vector<int>& edges) {
        if (node == -1)
            return;

        if (path.find(node) != path.end()) {
            ret = max(ret, l - length_until[node]);
            return;
        }

        if (length_until[node] != -1)
            return;

        length_until[node] = l;
        path.insert(node);
        dfs(edges[node], l + 1, path, edges);
    }

    int longestCycle(vector<int>& edges) {
        const int n = edges.size();

        length_until = vector<int>(n, -1);

        for (int i = 0; i < n; i++) {
            if (length_until[i] != -1)
                continue;

            unordered_set<int> curr_path;
            dfs(i, 0, curr_path, edges);
        }
        
        return ret;
    }
};