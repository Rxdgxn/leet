#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    int total = 0;

    void dfs(TreeNode* root, int mask) {
        mask ^= 1 << root->val;

        if (root->left != NULL) dfs(root->left, mask);
        if (root->right != NULL) dfs(root->right, mask);

        if (root->left == NULL && root->right == NULL) {
            total += (mask & (mask - 1)) == 0;
            return;
        }
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root, 0);
        return total;
    }
};