#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        ios::sync_with_stdio(false);
        cin.tie();

        priority_queue<long long> pq;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            long long s = 0;

            while (sz--) {
                auto n = q.front();
                q.pop();

                s += n->val;

                if (n->left != nullptr) q.push(n->left);
                if (n->right != nullptr) q.push(n->right);
            }

            pq.push(s);
        }

        if (pq.size() < k) return -1;

        k--;
        while (k--) {
            pq.pop();
        }

        return pq.top();
    }
};