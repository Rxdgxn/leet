#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    unordered_map<int, vector<int>> direct_children[2];

    void dfs(TreeNode* root, int idx) {
        if (root == nullptr) return;

        vector<int> tmp;
        
        if (root->left != nullptr) {
            tmp.push_back(root->left->val);
            dfs(root->left, idx);
        }
        if (root->right != nullptr) {
            tmp.push_back(root->right->val);
            dfs(root->right, idx);
        }

        sort(tmp.begin(), tmp.end());
        direct_children[idx][root->val] = tmp;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        dfs(root1, 0);
        dfs(root2, 1);

        return direct_children[0] == direct_children[1];
    }
};