struct ListNode {
    int val;
    ListNode* next;
};

class Solution {
public:
    void add(ListNode* &l, int x) {
        ListNode* q = new ListNode;
        q->val = x;
        q->next = 0;

        if (l == nullptr) {
            l = q;
            return;
        }
        
        auto c = l;
        while (c->next != nullptr)
            c = c->next;
        c->next = q;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *ret = new ListNode, *mid = new ListNode;
        auto copy = ret;

        int i = 1;
        while (i < left) {
            add(ret, head->val);
            head = head->next;
            i++;
        }
        while (i <= right) {
            ListNode *tmp = new ListNode;
            tmp->val = head->val;
            tmp->next = mid;
            mid = tmp;
            head = head->next;
            i++;
        }

        while (ret->next != nullptr)
            ret = ret->next;
        ret->next = mid;

        while (ret->next->next != nullptr)
            ret = ret->next;
        ret->next = head;

        return copy->next;
    }
};