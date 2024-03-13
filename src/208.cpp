#include "../include.h"

struct Node {
    Node* children[26];
    bool isword = false;

    Node() {
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    Node *root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *p = root;

        for (char c : word) {
            int i = c - 'a';
            if (!p->children[i]) p->children[i] = new Node();
            p = p->children[i];
        }
        p->isword = true;
    }
    
    bool search(string word, bool pre = false) {
        Node* p = root;

        for (char c : word) {
            int i = c - 'a';
            if (!p->children[i]) return false;
            p = p->children[i];
        }

        if (!pre) return p->isword;
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};