#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        auto curr = head;

        int n = 0;
        vector<int> vec(1000), rem(1000, 0);

        while (curr != nullptr) {
            vec[n++] = curr->val;
            curr = curr->next;
        }

        for (int i = 0; i < n; i++) {
            if (!rem[i]) {
                int sum = vec[i], j;

                for (j = i + 1; j < n && sum != 0; j++)
                    if (!rem[j])
                        sum += vec[j];

                if (sum == 0)
                    for (int k = i; k < j; k++)
                        rem[k] = 1;
            }
        }

        ListNode *ret = NULL;

        for (int i = 0; i < n; i++)
            if (rem[i] == 0) {
                ListNode *tmp = new ListNode;
                tmp->val = vec[i];
                tmp->next;

                if (ret == NULL) ret = tmp;
                else {
                    auto p = ret;
                    while (p->next != NULL) p = p->next;
                    p->next = tmp;
                }
            }

        return ret;
    }
};