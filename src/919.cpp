#include "../include.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class CBTInserter {
public:
    deque<TreeNode*> incomplete;
    TreeNode *root;

    CBTInserter(TreeNode* root) {
        this->root = root;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            if (node->left == nullptr && node->right == nullptr) {
                // Leaf, must be processed later
                incomplete.push_back(node);
            }
            else if (node->right == nullptr) {
                // Incomplete node, has higher priority
                incomplete.push_front(node);
                continue; // this prevents the first initial unbalanced left child be put in the deque twice
            }

            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
    }
    
    int insert(int val) {
        auto node = incomplete.front();
        incomplete.pop_front();

        if (node->left == nullptr) {
            node->left = new TreeNode(val);
            incomplete.push_front(node);
        }
        else {
            node->right = new TreeNode(val);
            incomplete.push_back(node->left);
            incomplete.push_back(node->right);
        }

        return node->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};