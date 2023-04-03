
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

    #define inRange(num) ((num) <= high && (num) >= low ? (num) : 0)

    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root->left == nullptr && root->right == nullptr) {
            return inRange(root->val);
        }
        else if (root->left == nullptr && root->right != nullptr) {
            return inRange(root->val) + rangeSumBST(root->right, low, high);
        }
        else if (root->left != nullptr && root->right == nullptr) {
            return inRange(root->val) + rangeSumBST(root->left, low, high);
        }
        else {
            return inRange(root->val) + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
    }
};