#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        stack<int> st;

        while (head != nullptr) {
            st.push(head->val);
            head = head->next;
        }

        int n = 0, k = 0;

        while (!st.empty()) {
            if (st.top()) {
                n += (1 << k);
            }

            k++;
            st.pop();
        }

        return n;
    }
};