#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    TreeNode *originalRoot;

    void helper(TreeNode* root, int key, TreeNode* parent) {
        if (root == NULL)
            return;

        if (root->val == key) {
            if (root == originalRoot) {
                if (root->right == nullptr) {
                    originalRoot = root->left;
                    delete root;

                    return;
                }

                TreeNode *it = root->right;

                while (it->left != nullptr)
                    it = it->left;

                it->left = root->left;

                originalRoot = root->right;
                delete root;

                return;
            }

            if (parent->val > key) {
                if (root->right == nullptr) {
                    parent->left = root->left;
                    delete root;
                    return;
                }

                TreeNode *it = root->right;

                while (it->left != nullptr)
                    it = it->left;

                it->left = root->left;

                parent->left = root->right;
                delete root;

                return;
            }

            if (root->left == nullptr) {
                parent->right = root->right;
                delete root;
                return;
            }

            TreeNode *it = root->left;

            while (it->right != nullptr)
                it = it->right;

            it->right = root->right;

            parent->right = root->left;
            delete root;

            return;
        }
        else if (root->val < key) {
            helper(root->right, key, root);
        }
        else {
            helper(root->left, key, root);
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        originalRoot = root;
        helper(root, key, NULL);

        return originalRoot;
    }
};