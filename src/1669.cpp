#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *curr = list1, *prev = NULL, *l2 = list2;
        int k = 0;

        while (k < a) {
            prev = curr;
            curr = curr->next;
            k++;
        }

        while (k <= b) {
            curr = curr->next;
            k++;
        }

        while (l2->next != nullptr)
            l2 = l2->next;

        l2->next = curr;

        prev->next = list2;

        return list1;
    }
};