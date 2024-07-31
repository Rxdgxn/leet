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
    void dfs(Node* root, int depth, int& d) {
        if (root->children.empty()) {
            d = max(d, depth);
            return;
        }

        depth++;
        for (auto& child : root->children) dfs(child, depth, d);
    }

    int maxDepth(Node* root) {
        if (root == nullptr) return 0;

        int d = 1;
        dfs(root, 1, d);

        return d;
    }
};