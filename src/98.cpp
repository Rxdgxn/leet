#include "../include.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    bool valid(TreeNode* root, long long l, long long r) {
        if (root == nullptr) return true;
        if (root->val > l && root->val < r)
            return valid(root->left, l, root->val) && valid(root->right, root->val, r);
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return valid(root, -2147483649, 2147483649);
    }
};