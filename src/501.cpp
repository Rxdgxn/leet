#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    unordered_map<int, int> aps;
    int max = 0;

    void dfs(TreeNode* root) {
        if (root == nullptr) return;

        aps[root->val]++;

        if (aps[root->val] > max) max = aps[root->val];

        dfs(root->right);
        dfs(root->left);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> ret;

        dfs(root);

        for (auto& [k, v] : aps)
            if (v == max) ret.push_back(k);

        return ret;
    }
};