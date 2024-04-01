#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    void dfs(TreeNode* root, int& s) {
        if (root->val % 2 == 0) {
            if (root->left) {
                if (root->left->left) s += root->left->left->val;
                if (root->left->right) s += root->left->right->val;
            }
            if (root->right) {
                if (root->right->left) s += root->right->left->val;
                if (root->right->right) s += root->right->right->val;
            }
        }

        if (root->left) dfs(root->left, s);
        if (root->right) dfs(root->right, s);
    }

    int sumEvenGrandparent(TreeNode* root) {
        int s = 0;
        dfs(root, s);

        return s;
    }
};