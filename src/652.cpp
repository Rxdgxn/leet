#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    unordered_map<string, int> mp;

    string helper(TreeNode *root, vector<TreeNode*>& ret) {
        if (root == nullptr)
            return "";

        string left = helper(root->left, ret);
        string right = helper(root->right, ret);

        string hash = to_string(root->val) + "-" + left + "-" + right;

        if (mp[hash] == 1)
            ret.push_back(root);
        
        mp[hash]++;
        return hash;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ret;

        helper(root, ret);
        
        return ret;
    }
};