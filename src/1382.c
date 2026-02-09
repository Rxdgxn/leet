#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode* newNode(int x) {
    TreeNode *n = malloc(sizeof(TreeNode));
    n->val = x;
    n->left = n->right = NULL;

    return n;
}

void traverse(TreeNode *root, int values[], int *count) {
    if (root == NULL)
        return;

    traverse(root->left, values, count);

    values[*count] = root->val;
    *count += 1;

    traverse(root->right, values, count);
}

TreeNode* constructBalanced(int values[], int lo, int hi) {
    if (lo >= hi)
        return NULL;

    int mid = (lo + hi) / 2;

    TreeNode *node = newNode(values[mid]);

    node->left = constructBalanced(values, lo, mid);
    node->right = constructBalanced(values, mid + 1, hi);
    
    return node;
}

TreeNode* balanceBST(TreeNode *root) {
    int values[10000];
    int count = 0;

    traverse(root, values, &count);

    return constructBalanced(values, 0, count);
}