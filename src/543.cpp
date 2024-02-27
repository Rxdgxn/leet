#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    int dfs(TreeNode* root, int& d) {
        if (root == nullptr) return 0;

        int l = dfs(root->left, d);
        int r = dfs(root->right, d);

        d = max(d, l + r);

        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        dfs(root, d);

        return d;
    }
};