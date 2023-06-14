#include "include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    
    vector<int> vals;

    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        vals.push_back(root->val);

        dfs(root->left);
        dfs(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        sort(vals.begin(), vals.end());
        
        int m = INT_MAX;
        for (int i = 1; i < vals.size(); i++) {
            m = min(m, vals[i] - vals[i - 1]);
        }

        return m;
    }
};