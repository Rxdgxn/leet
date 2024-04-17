#include "../include.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    string ret;

    void dfs(TreeNode* root, stack<char>& curr) {
        curr.push('a' + root->val);

        if (root->left == nullptr && root->right == nullptr) {
            string s;
            stack<char> cpy = curr;
            
            while (!cpy.empty()) {
                s.push_back(cpy.top());
                cpy.pop();
            }

            if (ret.empty() || strcmp(s.c_str(), ret.c_str()) < 0) ret = s;

            return;
        }

        if (root->left) {
            dfs(root->left, curr);
            curr.pop();
        }
        if (root->right) {
            dfs(root->right, curr);
            curr.pop();
        }
    }

    string smallestFromLeaf(TreeNode* root) {
        stack<char> st;
        
        dfs(root, st);

        return ret;
    }
};