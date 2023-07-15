struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    int s = 0;

    void dfs(TreeNode* t, int n) {
        if (t->left == nullptr && t->right == nullptr) s += n;
        
        if (t->left != nullptr) {
            dfs(t->left, n * 10 + t->left->val);
        }
        if (t->right != nullptr) {
            dfs(t->right, n * 10 + t->right->val);
        }
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, root->val);

        return s;
    }
};