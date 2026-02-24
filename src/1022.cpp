#include "../include.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    int sum = 0;

    void helper(TreeNode *root, int curr) {
        curr |= root->val;

        if (root->left == nullptr && root->right == nullptr) {
            sum += curr;
            return;
        }

        if (root->left != nullptr)
            helper(root->left, curr << 1);

        if (root->right != nullptr)
            helper(root->right, curr << 1);
    }

    int sumRootToLeaf(TreeNode* root) {
        helper(root, 0);
        return sum;
    }
};