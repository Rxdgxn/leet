#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    unordered_map<int, TreeNode*> inner, father;

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        vector<int> possible_roots;

        for (auto& d : descriptions) {
            int p = d[0], c = d[1];
            bool left = d[2];

            TreeNode* &parent = inner[p];
            TreeNode* &child = inner[c];

            possible_roots.push_back(p);

            if (parent == nullptr)
                parent = new TreeNode(p);

            if (child == nullptr)
                child = new TreeNode(c);

            father[c] = parent;

            if (left)
                parent->left = child;
            else
                parent->right = child;
        }

        for (int r : possible_roots)
            if (father[r] == nullptr)
                return inner[r];

        return nullptr;
    }
};