struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    int s = 0;

    void dfs(TreeNode* root, bool left) {
        if (root->left == nullptr && root->right == nullptr) {
            if (left) s += root->val;
            return;
        }

        if (root->left != nullptr) dfs(root->left, true);
        if (root->right != nullptr) dfs(root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (root->left != nullptr) dfs(root->left, true);
        if (root->right != nullptr) dfs(root->right, false);
        return s;
    }
};