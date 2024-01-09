#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    vector<vector<int>> seq;

    void dfs(TreeNode* r, int k) {
        if (r == NULL) return;

        if (r->left != NULL) dfs(r->left, k);
        if (r->right != NULL) dfs(r->right, k);

        if (r->left == NULL && r->right == NULL) seq[k].push_back(r->val);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        seq = vector<vector<int>>(2);
        dfs(root1, 0);
        dfs(root2, 1);

        return seq[0] == seq[1];
    }
};