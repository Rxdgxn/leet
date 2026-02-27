#include "../include.h"

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> orig_to_clone;

    Node* helper(Node *original) {
        Node *clone = new Node(original->val);
        vector<Node*> cloned_neighbors;
        
        orig_to_clone.insert({original, clone});

        for (Node *n : original->neighbors) {
            if (orig_to_clone.find(n) == orig_to_clone.end()) {
                cloned_neighbors.push_back(helper(n));
            }
            else {
                cloned_neighbors.push_back(orig_to_clone[n]);
            }
        }

        clone->neighbors = cloned_neighbors;

        return clone;
    }

    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;

        return helper(node);
    }
};