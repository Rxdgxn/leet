#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
};


class Solution {
public:

    void add(ListNode *&l , int x) {
        ListNode *q = new ListNode;
        q->val = x;
        q->next = NULL;

        if (l == nullptr) {
            l = q;
            return;
        }

        ListNode *t = l;
        while(t->next != nullptr) t = t->next;
        t ->next = q;
    }

    #define LIST(x) add(new_list, (x)->val);\
                (x) = (x)->next;
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto new_list = new ListNode, ret = new_list;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                LIST(list1);
            }
            else {
                LIST(list2);
            }
        }

        while (list1 != nullptr) {
            LIST(list1);
        }
        while (list2 != nullptr) {
            LIST(list2);
        }

        return ret->next;
    }
};