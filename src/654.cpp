#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int find(vector<int>& nums, int a, int b) {
        int mx = nums[a], ret = a;

        for (int i = a + 1; i <= b; i++)
            if (nums[i] > mx) {
                mx = nums[i];
                ret = i;
            }

        return ret;
    }

    void helper(TreeNode *root, int a, int b, char side, vector<int>& nums) {
        // [a, b]

        if (a > b) return;

        const int i = find(nums, a, b);
        TreeNode *n = new TreeNode(nums[i]);

        if (side == 'l') root->left = n;
        else root->right = n;

        helper(n, a, i - 1, 'l', nums);
        helper(n, i + 1, b, 'r', nums);
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        const int n = nums.size();

        const int i = find(nums, 0, n - 1);
        TreeNode *root = new TreeNode(nums[i]);

        helper(root, 0, i - 1, 'l', nums);
        helper(root, i + 1, n - 1, 'r', nums);

        return root;
    }
};