#include "../include.h"

struct Node {
    char val;
    Node *left, *right;
};

class Solution {
public:
    int n;
    string ret = "";

    void traverse(Node *root, string s) {
        if (root->left == nullptr) {
            const int sz = s.size();

            if (sz < n) {
                for (int i = 0; i < n - sz; i++)
                    s += '0';

                ret = s;
                return;
            }

            return;
        }

        s += '0';
        traverse(root->left, s);
        s.pop_back();

        if (ret == "") {
            if (root->right == nullptr) {
                const int sz = s.size();

                if (sz < n) {
                    for (int i = 0; i < n - sz; i++)
                        s += '1';

                    ret = s;
                    return;
                }

                return;
            }

            s += '1';
            traverse(root->right, s);
            s.pop_back();
        }
    }

    string findDifferentBinaryString(vector<string>& nums) {
        n = nums.size();

        Node *root = new Node();
        root->left = root->right = nullptr;

        for (string& s : nums) {
            Node *it = root;

            for (char ch : s) {
                if (ch == '0') {
                    if (it->left == nullptr) {
                        it->left = new Node();
                        it->left->val = '0';
                    }

                    it = it->left;
                }
                else {
                    if (it->right == nullptr) {
                        it->right = new Node();
                        it->right->val = '1';
                    }

                    it = it->right;
                }
            }
        }

        string s = "";
        traverse(root, s);

        return ret;
    }
};