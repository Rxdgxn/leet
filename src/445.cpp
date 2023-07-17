#include "../include.h"

struct ListNode {
    int val;
    ListNode* next;
};

class Solution {
public:
    void add(ListNode* &head, int x) {
        auto p = new ListNode;
        p->val = x;
        p->next = NULL;
        
        if (head == nullptr) {
            head = p;
            return;
        }

        while (head->next != nullptr) head = head->next;
        head->next = p;
    } 

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1, v2, sum;
        auto head = new ListNode, ret = head;

        while (l1 != nullptr) {
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            v2.push_back(l2->val);
            l2 = l2->next;
        }

        if (v1.size() < v2.size()) {
            swap(v1, v2);
        }
        const int diff = v1.size() - v2.size();
        int s, prev = 0;

        for (int i = v2.size() - 1; i >= 0; i--) {
            s = v2[i] + v1[diff + i] + prev;

            if (s > 9) {
                prev = 1;
                s -= 10;
            }
            else prev = 0;

            sum.push_back(s);
        }
        for (int i = diff - 1; i >= 0; i--) {
            s = v1[i] + prev;

            if (s > 9) {
                prev = 1;
                s -= 10;
            }
            else prev = 0;

            sum.push_back(s);
        }
        if (prev) sum.push_back(prev);

        for (int i = sum.size() - 1; i >= 0; i--) add(head, sum[i]);

        return ret->next;
    }
};