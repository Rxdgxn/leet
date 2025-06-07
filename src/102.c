#include <stdlib.h>

typedef struct TreeNode TreeNode;
struct TreeNode {
    int val;
    TreeNode *left, *right;
};

// -------------------------------------------

typedef struct TreeNode TreeNode;

int** levelOrder(TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    TreeNode* queue[2000];
    int st = 0, dr = 0;

    queue[dr++] = root;
    int *level_sizes = NULL;
    *returnSize = 0;

    int **levels = NULL;

    while (st < dr) {
        int size = dr - st;

        int *curr_level = malloc(size * sizeof(int));
        int len = 0;

        level_sizes = realloc(level_sizes, ++(*returnSize) * sizeof(int));
        level_sizes[*returnSize - 1] = size;

        while (size--) {
            TreeNode *tn = queue[st++];
            curr_level[len++] = tn->val;

            if (tn->left != NULL)
                queue[dr++] = tn->left;
            if (tn->right != NULL)
                queue[dr++] = tn->right;
        }

        levels = realloc(levels, *returnSize * sizeof(int*));
        levels[*returnSize - 1] = curr_level;
    }

    *returnColumnSizes = level_sizes;
    return levels;
}