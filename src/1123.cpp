#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    vector<TreeNode*> leaves;
    int md = -1; // max_depth

    void dfs(TreeNode *root, int depth, TreeNode *p) {
        if (root == nullptr)
            return;

        parent[root] = p;

        if (depth > md) {
            md = depth;
            leaves.clear();

            if (root->left == NULL && root->right == NULL)
                leaves.push_back(root);
        }
        else if (depth == md)
            leaves.push_back(root);

        dfs(root->left, depth + 1, root);
        dfs(root->right, depth + 1, root);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root, 0, nullptr);

        if (leaves.size() == 1)
            return leaves[0];

        unordered_set<TreeNode*> s;
        do {
            s.clear();

            for (auto l : leaves)
                s.insert(parent[l]);

            leaves = vector<TreeNode*>(s.begin(), s.end());
        } while (leaves.size() > 1);

        return leaves[0];
    }
};