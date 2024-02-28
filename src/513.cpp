#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    unordered_map<int, int> depths;
    unordered_map<int, bool> visited;
    int max_depth = 0;

    void dfs(TreeNode* root, int d) {
        if (root->left == nullptr && root->right == nullptr) {
            max_depth = max(max_depth, d);
            if (!visited[d]) {
                depths[d] = root->val;
                visited[d] = 1;
            }
            return;
        }

        if (root->left != nullptr) dfs(root->left, d + 1);
        if (root->right != nullptr) dfs(root->right, d + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return depths[max_depth];
    }
};