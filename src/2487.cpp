#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;

        while (head != nullptr) {
            st.push(head);
            head = head->next;
        }
        
        int m = st.top()->val;
        st.pop();

        auto ret = new ListNode(m);

        while (!st.empty()) {
            if (st.top()->val >= m) {
                m = st.top()->val;

                auto tmp = new ListNode();
                tmp->val = m;
                tmp->next = ret;

                ret = tmp;
            }

            st.pop();
        }

        return ret;
    }
};