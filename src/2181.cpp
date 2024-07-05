#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        stack<int> st;
        int x = 0;

        while (head != nullptr) {
            if (head->val == 0) {
                if (x) {
                    st.push(x);
                    x = 0;
                }
            }
            else x += head->val;

            head = head->next;
        }

        ListNode *node = new ListNode;

        while (!st.empty()) {
            x = st.top();
            st.pop();
            
            if (node->val != 0) {
                ListNode *t = new ListNode;
                t->val = x;
                t->next = node;

                node = t;
            }
            else node->val = x;
        }

        return node;
    }
};