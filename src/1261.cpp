struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void recover(TreeNode* t) {
    if (t->left != nullptr) {
        t->left->val = t->val * 2 + 1;
        recover(t->left);
    }
    if (t->right != nullptr) {
        t->right->val = t->val * 2 + 2;
        recover(t->right);
    }
}

class FindElements {
public:

    TreeNode* head;

    FindElements(TreeNode* root) {
        head = root;
        root->val = 0;
        recover(root);
    }

    bool dfs(TreeNode* t, int target) {
        if (t == nullptr) return false;
        if (t->val == target) return true;

        return dfs(t->left, target) || dfs(t->right, target);
    }
    
    bool find(int target) {
        return dfs(head, target);
    }
};