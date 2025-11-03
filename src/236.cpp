#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void dfs(TreeNode *root) {
        if (root->left != NULL) {
            parent[root->left] = root;
            dfs(root->left);
        }
        if (root->right != NULL) {
            parent[root->right] = root;
            dfs(root->right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        parent[root] = NULL;
        dfs(root);

        unordered_set<TreeNode*> visited;

        while (parent[p] != NULL) {
            visited.insert(p);
            p = parent[p];
        }
        
        visited.insert(p);

        while (visited.find(q) == visited.end()) {
            q = parent[q];
        }

        return q;
    }
};