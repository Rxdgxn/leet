#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;

        auto curr = head;
        vector<ListNode*> list(500);

        while (curr != nullptr) {
            list[n++] = curr;
            curr = curr->next;
        }

        if (n == 0) return head;

        k %= n;

        if (k == 0) return head;

        auto beg = list[n - k];
        list[n - k - 1]->next = NULL;

        curr = beg;
        while (curr->next != nullptr) curr = curr->next;
        curr->next = list[0];

        return beg;
    }
};