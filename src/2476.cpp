#include "../include.h"

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

class Solution {
public:
    vector<int> sorted;

    void flatten(TreeNode *root) {
        if (root == nullptr)
            return;

        flatten(root->left);
        sorted.push_back(root->val);
        flatten(root->right);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ret;
        flatten(root);

        for (int q : queries) {
            auto lb = lower_bound(sorted.begin(), sorted.end(), q);

            if (lb == sorted.end()) {
                ret.push_back({sorted.back(), -1});
                continue;
            }

            if (*lb == q) {
                ret.push_back({q, q});
                continue;
            }

            if (lb == sorted.begin()) {
                ret.push_back({-1, sorted[0]});
                continue;
            }

            ret.push_back({*prev(lb), *lb});
        }

        return ret;
    }
};