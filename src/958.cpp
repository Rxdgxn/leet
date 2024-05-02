#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int h = 0, inc = 0, height = 0;
        vector<int> level_nodes(32);

        while (!q.empty()) {
            int k = q.size(), nodes = 0;

            if ((1 << height) != k) inc++;

            if (inc >= 2) return false;

            while (k--) {
                auto n = q.front();
                q.pop();

                nodes++;
                
                if (n->left != nullptr) q.push(n->left);
                if (n->right != nullptr) q.push(n->right);
            }

            level_nodes[height++] = nodes;
        }

        q.push(root);

        while (!q.empty()) {
            int k = q.size(), nodes = 0;

            h++;

            while (k--) {
                auto n = q.front();
                q.pop();

                if (n->left != nullptr) {
                    q.push(n->left);
                    nodes++;
                }
                
                if (n->right != nullptr) {
                    if (n->left == nullptr) return false;
                    else {
                        q.push(n->right);
                        nodes++;
                    }
                }
                else {
                    if (nodes < level_nodes[h]) return false;
                }
            }
        }

        return true;
    }
};