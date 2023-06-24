#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    void addToEnd(ListNode* h, int x) {
        auto p = new ListNode;
        p->val = x;
        p->next = nullptr;
        
        if (h == nullptr) {
            h = p;
            return;
        }
        while (h->next != nullptr) {
            h = h->next;
        }
        h->next = p;
    }

    ListNode* partition(ListNode* head, int x) {
        vector<int> v1, v2;
        auto ret = new ListNode;

        while (head != nullptr) {
            if (head->val < x) v2.push_back(head->val);
            else v1.push_back(head->val);
            head = head->next;
        }

        for (int i : v2) {
            addToEnd(ret, i);
        }
        for (int i : v1) {
            addToEnd(ret, i);
        }

        return ret->next;
    }
};