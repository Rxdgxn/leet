#include <stdlib.h>

typedef struct TreeNode TreeNode;
struct TreeNode {
    int val;
    TreeNode *left, *right;
};

#define NOT_NEEDED 0
#define NO_CAMERA 1
#define HAS_CAMERA 2

int dfs(TreeNode* root, int* cameras) {
    if (root == NULL) return NOT_NEEDED;

    int l = dfs(root->left, cameras);
    int r = dfs(root->right, cameras);

    if (l == NO_CAMERA || r == NO_CAMERA) {
        *cameras += 1;
        return HAS_CAMERA;
    }

    if (l == HAS_CAMERA || r == HAS_CAMERA)
        return NOT_NEEDED;

    return NO_CAMERA;
}

int minCameraCover(TreeNode* root) {
    int cameras = 0;

    if (dfs(root, &cameras) == NO_CAMERA) cameras++;

    return cameras;
}