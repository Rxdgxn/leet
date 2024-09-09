#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    void add(ListNode* head, int x) {
        ListNode *q = new ListNode;
        q->val = x;
        q->next = NULL;

        if (head == nullptr) head = q;
        else {
            ListNode *it = head;

            while (it->next != nullptr) it = it->next;

            it->next = q;
        }
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<int> list;
        int len = 0;

        while (head != nullptr) {
            len++;
            list.push_back(head->val);
            head = head->next;
        }

        int avg = len / k, rem = len % k;

        vector<ListNode*> ret;
        int i = 0;

        while (len) {
            ListNode *n = new ListNode;

            for (int j = 0; j < avg; j++) add(n, list[i++]);
            len -= avg;

            if (rem) {
                rem--;
                len--;
                add(n, list[i++]);
            }

            ret.push_back(n->next);
        }

        while (ret.size() != k) ret.push_back({});

        return ret;
    }
};