struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        return root->val + dfs(root->left) + dfs(root->right);
    }

    bool checkTree(TreeNode* root) {
        return root->val == (dfs(root->left) + dfs(root->right));
    }
};