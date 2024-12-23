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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        vector<TreeNode*> nodes;

        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();

            if (level % 2) {
                nodes.push_back(node);

                const int size = (1 << level);

                if (nodes.size() == size) {
                    vector<int> reversed(size);

                    for (int i = 0; i < size; i++)
                        reversed[i] = nodes[size - 1 - i]->val;

                    for (int i = 0; i < size; i++)
                        nodes[i]->val = reversed[i];

                    nodes.clear();
                }
            }

            if (node->left != nullptr) {
                q.push({node->left, level + 1});
                q.push({node->right, level + 1});
            }
        }

        return root;
    }
};