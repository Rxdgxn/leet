#include "../include.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    int mx = 1;

    void dfs(TreeNode* root, int k) {
        if (root->left != nullptr) dfs(root->left, k + 1);
        if (root->right != nullptr) dfs(root->right, k + 1);

        if (root->left == nullptr && root->right == nullptr) mx = max(mx, k);
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        dfs(root, 1);
        return mx;
    }
};