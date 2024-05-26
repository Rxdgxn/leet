#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    unordered_map<int, int> ancestors, levels;
    unordered_map<int, TreeNode*> nodes;

    void dfs(TreeNode* root, int level) {
        nodes[root->val] = root;
        levels[root->val] = level;

        if (root->left != nullptr) {
            ancestors[root->left->val] = root->val;
            dfs(root->left, level + 1);
        }
        if (root->right != nullptr) {
            ancestors[root->right->val] = root->val;
            dfs(root->right, level + 1);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* P, TreeNode* Q) {
        ancestors[root->val] = INT_MIN;
        dfs(root, 0);

        int p = P->val, q = Q->val;

        while (levels[p] > levels[q]) p = ancestors[p];
        while (levels[q] > levels[p]) q = ancestors[q];

        while (p != q) {
            if (p == INT_MIN) return root;

            p = ancestors[p];
            q = ancestors[q];
        }

        return nodes[p];
    }
};