#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    typedef long long ll;

    int ret = 0;

    // This seems to run slower than the O(n^2) solution, which would substract each prefix from currSum and check against targetSum
    void dfs(TreeNode *root, int targetSum, unordered_map<ll, int>& prefixes, ll currSum) {
        if (root == nullptr)
            return;

        currSum += root->val;

        if (currSum == targetSum)
            ret++;
        
        ret += prefixes[currSum - targetSum];

        prefixes[currSum]++;
        dfs(root->left, targetSum, prefixes, currSum);
        dfs(root->right, targetSum, prefixes, currSum);
        prefixes[currSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }

        ret += (root->val == targetSum);

        unordered_map<ll, int> prefixes;
        prefixes[root->val]++;

        dfs(root->left, targetSum, prefixes, root->val);
        dfs(root->right, targetSum, prefixes, root->val);

        return ret;
    }
};