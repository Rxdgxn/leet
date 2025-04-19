#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

typedef struct TreeNode TreeNode;

void sum_dfs(TreeNode *root, int *node_count, int *sum, int *global_count) {
    if (root == NULL)
        return;

    int curr_nodes = 1, curr_sum = root->val;

    if (root->left != NULL) {
        int ln = 0, ls = 0;
        sum_dfs(root->left, &ln, &ls, global_count);

        curr_nodes += ln;
        curr_sum += ls;
    }
    if (root->right != NULL) {
        int ln = 0, ls = 0;
        sum_dfs(root->right, &ln, &ls, global_count);

        curr_nodes += ln;
        curr_sum += ls;
    }

    *node_count += curr_nodes;
    *sum += curr_sum;

    if (*sum / *node_count == root->val)
        *global_count += 1;
}

int averageOfSubtree(TreeNode* root) {
    int nodes = 0, node_count = 0, sum = 0;
    sum_dfs(root, &node_count, &sum, &nodes);

    return nodes;
}