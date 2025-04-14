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

    ListNode *first = NULL, *second = head;
    head = head->next;

    int duplicate = 0;

    while (head != NULL) {
        if (head->val == second->val) {
            while (head != NULL && head->val == second->val) {
                ListNode *n = head->next;
                free(head);
                head = n;
            }

            if (head == NULL) {
                if (first == NULL) {
                    free(second);
                    return NULL;
                }

                first->next = NULL;
                return start;
            }

            if (first == NULL) {
                free(second);
                start = head;
                second = head;
                head = head->next;
                continue;
            }

            free(second);
            first->next = head;
            second = head;
            head = head->next;
            continue;
        }

        first = second;
        second = head;
        head = head->next;
    }

    return start;
}