#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    void dfs(TreeNode *root, int v, int d, int depth) {
        if (d == depth - 1) {
            auto lnode = new TreeNode, rnode = new TreeNode;
            lnode->val = v;
            rnode->val = v;
            lnode->left = root->left;
            rnode->right = root->right;
            
            root->left = lnode;
            root->right = rnode;
        }
        else {
            if (root->left != nullptr) dfs(root->left, v, d + 1, depth);
            if (root->right != nullptr) dfs(root->right, v, d + 1, depth);
        }
    }

    TreeNode* addOneRow(TreeNode *root, int val, int depth) {
        auto ret = root;

        if (depth != 1) dfs(root, val, 1, depth);
        else {
            auto node = new TreeNode;
            node->val = val;
            node->left = root;
            node->right = NULL;
            
            ret = node;
        }

        return ret;
    }
};