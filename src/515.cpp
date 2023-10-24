#include "../include.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    vector<int> ret;

    void dfs(TreeNode* root, int d) {
        if (root == nullptr) return;

        if (ret.size() == d) ret.push_back(root->val);
        else ret[d] = max(root->val, ret[d]);

        if (root->left != nullptr) dfs(root->left, d + 1);
        if (root->right != nullptr) dfs(root->right, d + 1);
    }


    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);

        return ret;
    }
};