#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

typedef struct Node Node;

Node* newNode(int x) {
    Node *n = malloc(sizeof(Node));

    n->val = x;
    n->next = NULL;

    return n;
}

int minimumPairRemoval(int* nums, int numsSize) {
    if (numsSize == 1)
        return 0;

    Node *head = newNode(nums[0]);
    Node *iter = head;

    for (int i = 1; i < numsSize; i++) {
        iter->next = newNode(nums[i]);
        iter = iter->next;
    }

    int total_iterations = 0;

    while (1) {
        int min = 1 << 31 - 1;
        int non_decreasing = 1;

        Node *found = NULL;

        for (iter = head; iter->next != NULL; iter = iter->next) {
            if (iter->val + iter->next->val < min) {
                min = iter->val + iter->next->val;
                found = iter;
            }

            if (iter->val > iter->next->val)
                non_decreasing = 0;
        }

        if (found == NULL || non_decreasing)
            break;

        found->val += found->next->val;

        Node *remove = found->next;
        found->next = found->next->next;
        free(remove);

        total_iterations += 1;
    }

    return total_iterations;
}