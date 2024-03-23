#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v, reordered;
        int n = 0;

        auto start = head;

        while (head != nullptr) {
            n++;
            v.push_back(head);
            head = head->next;
        }

        int st, dr;

        if (n % 2 == 0) {
            st = (n - 1) / 2;
            dr = n / 2;
        }
        else {
            reordered.push_back(v[n / 2]);
            st = n / 2 - 1;
            dr = n / 2 + 1;
        }

        while (st >= 0) {
            reordered.push_back(v[dr++]);
            reordered.push_back(v[st--]);
        } 

        ListNode *t = NULL;

        for (int i = 0; i < n; i++) {
            t = reordered[i];
            t->next = head;
            head = t;
        }
    }
};