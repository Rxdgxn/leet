#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ios::sync_with_stdio(false);
        cin.tie();
        
        ListNode *r = NULL;

        unordered_map<long long, int> vals;

        while (headA != nullptr) {
            vals[(long long)(headA)]++;
            headA = headA->next;
        }

        while (headB != nullptr) {
            if (vals[(long long)(headB)]) {
                r = headB;
                break;
            }
            headB = headB->next;
        }

        return r;
    }
};