#include "../include.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    unordered_map<int, vector<int>> graph;

    void convert(TreeNode* t, int parent) {
        if (t == NULL) return;

        auto& list = graph[t->val];
        
        if (parent != 0) list.push_back(parent);
        if (t->left != NULL) list.push_back(t->left->val);
        if (t->right != NULL) list.push_back(t->right->val);

        convert(t->left, t->val);
        convert(t->right, t->val);
    }

    int amountOfTime(TreeNode* root, int start) {
        // max distance from start to any
        
        convert(root, 0);

        queue<int> q;
        q.push(start);

        unordered_map<int, bool> visited;
        visited[start] = 1;

        int minute = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz > 0) {
                int x = q.front();
                q.pop();

                for (int n : graph[x]) {
                    if (!visited[n]) {
                        visited[n] = 1;
                        q.push(n);
                    }
                }

                sz--;
            }

            minute++;
        }

        return minute - 1;
    }
};