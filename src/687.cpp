#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    queue<TreeNode*> q;
    int max_len = 0;

    int height(TreeNode *root, int prev) {
        if (root == nullptr)
            return 0;

        if (root->val != prev) {
            q.push(root);
            return 0;
        }

        int l = height(root->left, root->val);
        int r = height(root->right, root->val);

        int nodes = 1 + max(l, r);

        max_len = max(max_len, l + r);

        return nodes;
    }

    int longestUnivaluePath(TreeNode *root) {
        if (root == nullptr)
            return 0;

        q.push(root);

        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            height(node, node->val);
        }

        return max_len;
    }
};