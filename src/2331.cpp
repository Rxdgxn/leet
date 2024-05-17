#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
            return root->val;

        if (root->val == 2) return evaluateTree(root->left) || evaluateTree(root->right);
        else return evaluateTree(root->left) && evaluateTree(root->right);
    }
};