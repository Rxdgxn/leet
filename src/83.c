#include <stdlib.h>

typedef struct ListNode ListNode;
struct ListNode {
    int val;
    ListNode *next;
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL)
        return NULL;

    ListNode *start = head;

    ListNode *prev = head;
    head = head->next;

    while (head != NULL) {
        if (head->val == prev->val) {
            prev->next = head->next;
            free(head);
            head = prev;
        }

        prev = head;
        head = head->next;
    }

    return start;
}