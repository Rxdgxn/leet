#include "../include.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    void dfs(TreeNode* root) {
        if (root == NULL) return;

        swap(root->left, root->right);
        if (root->left != NULL) dfs(root->left);
        if (root->right != NULL) dfs(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        auto ret = root;
        dfs(root);
        return ret;
    }
};