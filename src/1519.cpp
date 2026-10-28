#include "../include.h"

class Solution {
public:
    vector<vector<int>> tree;
    vector<int> ret;

    void dfs(int node, int prev, const string& labels, int countSubtree[26]) {
        int local[26] = {0};
        local[labels[node] - 'a']++;

        for (int child : tree[node]) {
            if (child != prev) {
                dfs(child, node, labels, local);
            }
        }

        ret[node] = local[labels[node] - 'a'];

        for (int i = 0; i < 26; i++) {
            countSubtree[i] += local[i];
        }
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        tree = vector<vector<int>>(n);
        ret = vector<int>(n);

        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        int countSubtree[26] = {0};
        dfs(0, -1, labels, countSubtree);

        return ret;
    }
};