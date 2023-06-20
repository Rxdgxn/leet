#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        int x1 = 0, y1 = 0, x2 = n - 1, y2 = m - 1;

        while (head != nullptr) {            
            for (int i = x1; i <= x2 && head != nullptr; i++) {
                matrix[y1][i] = head->val;
                head = head->next;
            }
            y1++;

            for (int i = y1; i <= y2 && head != nullptr; i++) {
                matrix[i][x2] = head->val;
                head = head->next;
            }
            x2--;

            for (int i = x2; i >= x1 && head != nullptr; i--) {
                matrix[y2][i] = head->val;
                head = head->next;
            }
            y2--;

            for (int i = y2; i >= y1 && head != nullptr; i--) {
                matrix[i][x1] = head->val;
                head = head->next;
            }
            x1++;
        }

        return matrix;
    }
};