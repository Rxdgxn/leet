#include <stdlib.h>

typedef struct ListNode ListNode;

struct ListNode {
    int val;
    ListNode *next;
};

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *s = NULL;

    int l = 0;

    ListNode* nodes[5000];
    int nodes_count = 0;

    ListNode* portions[5000];
    int portions_count = 0;

    while (head != NULL) {
        l++;

        nodes[nodes_count++] = head;

        if (l == k) {
            head = head->next;

            for (int i = nodes_count - 1; i > 0; i--)
                nodes[i]->next = nodes[i - 1];

            nodes[0]->next = NULL;

            portions[portions_count++] = nodes[nodes_count - 1];

            nodes_count = 0;
            l = 0;

            continue;
        }

        head = head->next;
    }

    for (int i = 0; i < portions_count - 1; i++) {
        s = portions[i];

        while (s->next != NULL)
            s = s->next;

        s->next = portions[i + 1];
    }

    if (l != 0) {
        s = portions[portions_count - 1];

        while (s->next != NULL)
            s = s->next;

        s->next = nodes[0];
    }

    return portions[0];
}