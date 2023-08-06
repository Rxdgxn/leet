#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto slow = head, fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true;
        }
        
        return false;
    }
};