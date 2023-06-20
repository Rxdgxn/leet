struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;

        while (head != nullptr) {
            ListNode *tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }

        return prev;
    }
};