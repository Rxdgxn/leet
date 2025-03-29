#include <stdlib.h>

typedef struct TreeNode TreeNode;
struct TreeNode {
    int val;
    TreeNode *left, *right;
};

void dfs(TreeNode *root, TreeNode **found, int val) {
    if (*found != NULL || root == NULL)
        return;

    if (val < root->val) {
        if (root->left == NULL) {
            *found = root;
            return;
        }
        dfs(root->left, found, val);
    }
    else {
        if (root->right == NULL) {
            *found = root;
            return;
        }
        dfs(root->right, found, val);
    }
}

TreeNode* newNode(int val) {
    TreeNode *n = (TreeNode*) malloc(sizeof(TreeNode));
    n->val = val;
    n->left = n->right = NULL;

    return n;
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode *found = NULL; // first found leaf

    dfs(root, &found, val);

    if (found == NULL)
        return newNode(val);

    if (val < found->val)
        found->left = newNode(val);
    else
        found->right = newNode(val);

    return root;
}