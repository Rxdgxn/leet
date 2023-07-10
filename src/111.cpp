#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    vector<int> d;

    void dfs(TreeNode* t, int x) {
        if (t->left == nullptr && t->right == nullptr) d.push_back(x);
        if (t->left != nullptr) dfs(t->left, x + 1);
        if (t->right != nullptr) dfs(t->right, x + 1);
    }

    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root, 1);
        
        int m = INT_MAX;
        for (int x : d) m = min(m, x);

        return m;
    }
};