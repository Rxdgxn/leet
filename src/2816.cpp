#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie();

        stack<int> st;

        while (head != nullptr) {
            st.push(head->val);
            head = head->next;
        }

        auto ret = new ListNode(st.top() * 2 % 10, NULL);
        int r = st.top() * 2 / 10;
        st.pop();

        while (!st.empty()) {
            auto t = new ListNode((st.top() * 2 + r) % 10, ret);
            r = (st.top() * 2 + r) / 10;

            ret = t;
            st.pop();
        }

        if (r) {
            auto t = new ListNode(1, ret);
            ret = t;
        }

        return ret;
    }
};