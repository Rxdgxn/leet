#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> vec;
        int len = 0;

        while (head != nullptr) {
            vec.push_back(head);
            len++;

            head = head->next;
        }

        return vec[len / 2];
    }
};