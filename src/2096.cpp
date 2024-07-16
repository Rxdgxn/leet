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
    unordered_map<int, pair<int, int>> ancestors;
    unordered_map<int, vector<pair<int, char>>> tree;

    string join;

    void dfs(TreeNode* root, int prev, int level) {
        if (root == nullptr) return;

        ancestors[root->val] = {prev, level};

        if (root->left != nullptr) tree[root->val].push_back({root->left->val, 'L'});
        if (root->right != nullptr) tree[root->val].push_back({root->right->val, 'R'});

        dfs(root->left, root->val, level + 1);
        dfs(root->right, root->val, level + 1);
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string ret, tmp;

        dfs(root, 0, 0);

        int s = startValue, d = destValue;

        while (ancestors[s].second > ancestors[d].second) {
            s = ancestors[s].first;
            ret += 'U';
        }
        while (ancestors[s].second < ancestors[d].second) {
            d = ancestors[d].first;
        }

        while (s != d) {
            s = ancestors[s].first;
            ret += 'U';
            d = ancestors[d].first;
        }

        stack<char> st;
        while (destValue != d) {
            if (tree[ancestors[destValue].first][0].first == destValue) {
                st.push(tree[ancestors[destValue].first][0].second);
            }
            else if (tree[ancestors[destValue].first][1].first == destValue) {
                st.push('R');
            }

            destValue = ancestors[destValue].first;
        }

        while (!st.empty()) {
            ret.push_back(st.top());
            st.pop();
        }
 
        return ret;
    }
};