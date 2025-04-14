#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
ListNode* mergeKLists(ListNode** lists, int listsSize) {
    ListNode *start = NULL, *next = start;

    int all_null = 0;

    while (!all_null) {
        all_null = 1;
        int min = INT_MAX;

        for (int i = 0; i < listsSize; i++) {
            if (lists[i] == NULL) continue;

            all_null = 0;

            if (lists[i]->val < min)
                min = lists[i]->val;
        }

        for (int i = 0; i < listsSize; i++) {
            if (lists[i] == NULL) continue;

            if (lists[i]->val == min) {
                if (next == NULL) {
                    next = malloc(sizeof(ListNode));
                    next->val = min;
                    next->next = NULL;

                    start = next;
                }
                else {
                    next->next = malloc(sizeof(ListNode));
                    next = next->next;

                    next->val = min;
                    next->next = NULL;
                }

                lists[i] = lists[i]->next;
            }
        }
    }

    return start;
}