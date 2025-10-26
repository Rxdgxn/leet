#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    string ret;

    void dfs(TreeNode *root) {
        ret += to_string(root->val);

        if (root->left != nullptr) {
            ret += '(';
            dfs(root->left);
            ret += ')';
        }
        else if (root->right != nullptr) {
            ret += "()";
        }

        if (root->right != nullptr) {
            ret += '(';
            dfs(root->right);
            ret += ')';
        }
    }

    string tree2str(TreeNode *root) {
        if (root == nullptr)
            return "";

        dfs(root);
        return ret;
    }
};