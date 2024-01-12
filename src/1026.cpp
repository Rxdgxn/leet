#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    int dfs(TreeNode* t, int mn, int mx) {
        if (t == NULL) return mx - mn;

        mn = min(mn, t->val);
        mx = max(mx, t->val);

        int l = dfs(t->left, mn, mx), r = dfs(t->right, mn, mx);
        
        return max(l, r);
    }

    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};