#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "null";
        }

        string s = to_string(root->val);
        return s + ',' + serialize(root->left) + ',' + serialize(root->right);
    }

    TreeNode* build(vector<string>& data, int *i) {
        if (data[*i] == "null") {
            return nullptr;
        }

        auto root = new TreeNode;
        root->val = stoi(data[*i]);

        *i += 1;
        root->left = build(data, i);
        *i += 1;
        root->right = build(data, i);

        return root;
    }

    TreeNode* deserialize(string data) {
        vector<string> parsed;
        string x = "";

        for (char ch : data) {
            if (ch == ',') {
                parsed.push_back(x);
                x.clear();
            }
            else {
                x += ch;
            }
        }

        parsed.push_back(x);

        int i = 0;
        return build(parsed, &i);
    }
};