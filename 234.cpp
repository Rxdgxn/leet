struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int list[100001], k = 0;

        while (head != nullptr) {
            list[k++] = head->val;
            head = head->next;
        }

        for (int i = 0; i < k / 2; i++) {
            if (list[i] != list[k - 1 - i]) return false;
        }

        return true;
    }
};