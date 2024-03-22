#include "../include.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    vector<vector<int>> ret;
    int t;

    void dfs(TreeNode* root, vector<int>& path, int s) {
        path.push_back(root->val);
        s += root->val;

        if (root->left == nullptr && root->right == nullptr) {
            if (s == t) {
                ret.push_back(path);
            }
            return;
        }

        if (root->left != nullptr) {
            int aux = s;
            dfs(root->left, path, s);
            path.pop_back();
            s = aux;
        }
        if (root->right != nullptr) {
            int aux = s;
            dfs(root->right, path, s);
            path.pop_back();
            s = aux;
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return {};

        vector<int> path;
        int s = 0;
        t = targetSum;

        dfs(root, path, s);

        return ret;
    }
};