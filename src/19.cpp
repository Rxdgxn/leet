struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    int lsize(ListNode* &head) {
        int s = 1;
        while (head->next != nullptr) {
            s++;
            head = head->next;
        }
        return s;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto t = head, q = head;
        int size = lsize(t), k = 0;
        if (size == 1) return nullptr;
        if (size == n) return head->next;
        while (k < size - n - 1) {
            q = q->next;
            k++;
        }
        if (q->next != nullptr)
            q->next = q->next->next;
        return head;
    }
};