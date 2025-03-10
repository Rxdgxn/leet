#include "../include.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
private:
    int compute(vector<int>& arr) {
        int swaps = 0;

        unordered_map<int, int> position;

        for (int i = 0; i < arr.size(); i++)
            position[arr[i]] = i;

        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        for (int i = 0; i < arr.size(); i++)
            if (arr[i] != sorted[i]) {
                swaps++;
                
                int p = position[sorted[i]];
                position[arr[i]] = p;

                swap(arr[i], arr[p]);
            }

        return swaps;
    }
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        unordered_map<int, vector<int>> levels;
        
        int depth = 0, swaps = 0;

        q.push(root);

        while (!q.empty()) {
            int k = q.size();

            vector<int> arr;

            while (k--) {
                TreeNode *n = q.front();
                q.pop();

                arr.push_back(n->val);

                if (n->left != nullptr)
                    q.push(n->left);
                if (n->right != nullptr)
                    q.push(n->right);
            }

            levels[depth++] = arr;
        }

        for (auto& [_, arr] : levels)
            swaps += compute(arr);

        return swaps;
    }
};