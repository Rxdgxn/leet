#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    TreeNode* recoverFromPreorder(string traversal) {
        traversal += '-';

        int prev_depth = 0, depth = 0, val = 0, i;
        const int n = traversal.size();

        for (i = 0; i < n && traversal[i] != '-'; i++)
            val = val * 10 + traversal[i] - '0';

        TreeNode *init = new TreeNode(val);
        TreeNode *root = init;

        val = 0;

        for (; i < n; i++) {
            if (traversal[i] == '-') {
                if (val != 0) {
                    if (depth > prev_depth) {
                        init->left = new TreeNode(val);
                        parent[init->left] = init;
                        init = init->left;
                    }
                    else if (depth == prev_depth) {
                        init = parent[init];
                        init->right = new TreeNode(val);
                        parent[init->right] = init;
                        init = init->right;
                    }
                    else {
                        for (int j = 0; j <= prev_depth - depth; j++)
                            init = parent[init];
                        
                        init->right = new TreeNode(val);
                        parent[init->right] = init;
                        init = init->right;
                    }

                    val = 0;
                    prev_depth = depth;
                    depth = 0;
                }

                depth++;
            }
            else val = val * 10 + traversal[i] - '0';
        }

        return root;
    }
};