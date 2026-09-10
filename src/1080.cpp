#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    TreeNode* dfs(TreeNode *root, int curr_sum, int limit) {
        if (root == nullptr)
            return nullptr;

        if (root->left == nullptr && root->right == nullptr) {
            if (curr_sum + root->val < limit) return nullptr;
            return root;
        }

        root->left = dfs(root->left, curr_sum + root->val, limit);
        root->right = dfs(root->right, curr_sum + root->val, limit);

        if (root->left == nullptr && root->right == nullptr)
            return nullptr;
        return root;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return dfs(root, 0, limit);
    }
};