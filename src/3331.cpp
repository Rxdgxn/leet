#include "../include.h"

class Solution {
public:
    unordered_map<char, vector<int>> last_node_of_val;
    unordered_map<int, int> subtree_size;

    int get_size(int root, unordered_map<int, vector<int>>& tree) {
        int size = 1;

        for (int child : tree[root])
            size += get_size(child, tree);

        return subtree_size[root] = size;
    }

    void dfs(int root, string& s, unordered_map<int, vector<int>>& tree, unordered_map<int, vector<int>>& new_tree) {
        last_node_of_val[s[root]].push_back(root);

        for (int child : tree[root]) {
            if (!last_node_of_val[s[child]].empty()) {
                int ancestor = last_node_of_val[s[child]].back();
                new_tree[ancestor].push_back(child);
            }
            else {
                new_tree[root].push_back(child);
            }

            dfs(child, s, tree, new_tree);
        }

        last_node_of_val[s[root]].pop_back();
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int root;
        unordered_map<int, vector<int>> tree, new_tree;

        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == -1) {
                root = i;
                continue;
            }

            tree[parent[i]].push_back(i);
        }

        dfs(root, s, tree, new_tree);
        get_size(root, new_tree);

        vector<int> ret(parent.size());

        for (int i = 0; i < parent.size(); i++)
            ret[i] = subtree_size[i];

        return ret;
    }
};