#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    vector<string> possibilities;

    void dfs(TreeNode* current_leaf, string current_word) {
        if (current_leaf->left == nullptr && current_leaf->right == nullptr)
            possibilities.push_back(current_word);

        if (current_leaf->left != nullptr)
            dfs(current_leaf->left, current_word + to_string(current_leaf->left->val) + "->");
        if (current_leaf->right != nullptr)
            dfs(current_leaf->right, current_word + to_string(current_leaf->right->val) + "->");
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        dfs(root, to_string(root->val) + "->");
        
        string parsed;
        while (head != nullptr) {
            parsed += to_string(head->val) + "->";
            head = head->next;
        }

        for (const string& s : possibilities)
            if (s.find(parsed) != string::npos)
                return true;

        return false;
    }
};