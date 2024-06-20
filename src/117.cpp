#include "../include.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;

        Node *ret = root;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int k = q.size();

            while (k--) {
                auto n = q.front();
                q.pop();

                if (k > 0) n->next = q.front();

                if (n->left != NULL) q.push(n->left);
                if (n->right != NULL) q.push(n->right);
            }
        }

        return ret;
    }
};