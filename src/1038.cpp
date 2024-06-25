#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    int s = 0;

    void dfs(TreeNode* root) {
        if (root != nullptr) {
            dfs(root->right);
            s += root->val;
            root->val = s;
            dfs(root->left);
        }
    }

    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        return root;
    }
};