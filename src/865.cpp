#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    unordered_map<int, int> visit_count, depth, parent;
    int max_depth = 0;
    unordered_map<int, TreeNode*> final_map;

    void dfs(TreeNode *root, int d, int p) {
        if (root == nullptr)
            return;

        depth[root->val] = d;
        parent[root->val] = p;
        final_map[root->val] = root;

        max_depth = max(max_depth, d);

        dfs(root->left, d + 1, root->val);
        dfs(root->right, d + 1, root->val);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, 0, -1);

        unordered_set<int> leaves;

        for (auto& [k, v] : depth)
            if (v == max_depth)
                leaves.insert(k);

        while (leaves.size() > 1) {
            vector<int> tmp;

            for (int l : leaves)
                tmp.push_back(parent[l]);

            leaves.clear();

            for (int p : tmp)
                leaves.insert(p);
        }

        return final_map[*leaves.begin()];
    }
};