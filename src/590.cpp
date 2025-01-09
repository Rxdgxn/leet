#include "../include.h"

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> nodes;

    void dfs(Node* root) {
        if (root->children.empty()) return;

        for (Node *child : root->children) {
            dfs(child);
            nodes.push_back(child->val);
        }
    }

    vector<int> postorder(Node* root) {
        if (root == nullptr) return nodes;

        dfs(root);
        nodes.push_back(root->val);

        return nodes;
    }
};