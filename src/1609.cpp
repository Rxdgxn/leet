#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie();
        
        queue<TreeNode*> q;
        int level = 0;
        
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int prev;
            
            if (level % 2 == 1) prev = INT_MAX;
            else prev = INT_MIN;

            while (size--) {
                auto n = q.front();
                q.pop();
                
                if (level % 2 == 0 && (prev >= n->val || n->val % 2 == 0)) return false;
                if (level % 2 == 1 && (prev <= n->val || n->val % 2 == 1)) return false;

                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);

                prev = n->val;
            }

            level++;
        }

        return true;
    }
};