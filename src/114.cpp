struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    // TODO: Maybe try this in O(1) space
    TreeNode *result;
    TreeNode *last;
    TreeNode *original_root;

    void dfs(TreeNode *curr_node) {
        if (curr_node == nullptr)
            return;

        result->val = curr_node->val;
        result->left = nullptr;
        result->right = new TreeNode;

        last = result;
        result = result->right;

        dfs(curr_node->left);
        dfs(curr_node->right);

        if (curr_node != original_root)
            delete curr_node;
    }

    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;

        original_root = root;
        result = new TreeNode;
        TreeNode *new_root = result;
        dfs(root);

        // Get rid of the extra node
        delete result;
        last->right = nullptr;

        root->right = new_root->right;
        root->left = nullptr;
    }
};