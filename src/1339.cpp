#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    typedef unsigned long long u64;

    unordered_map<TreeNode*, u64> dp;
    u64 max_prod = 0;
    u64 total_sum;

    u64 dfs(TreeNode *root) {
        if (root == nullptr)
            return 0;

        dp[root] = (u64)root->val + dfs(root->left) + dfs(root->right);
        return dp[root];
    }

    // another dfs, try to remove certain edges and get max
    void remove_edges(TreeNode *root) {
        if (root == nullptr)
            return;

        if (dp[root->left] > dp[root->right]) {
            max_prod = max(max_prod, dp[root->left] * (total_sum - dp[root->left]));
            remove_edges(root->left);
        }
        else {
            max_prod = max(max_prod, dp[root->right] * (total_sum - dp[root->right]));
            remove_edges(root->right);
        }
    }

    int maxProduct(TreeNode* root) {
        dfs(root);
        total_sum = dp[root];
        dp[NULL] = 0;
        
        remove_edges(root);

        return (int)(max_prod % 1000000007);
    }
};