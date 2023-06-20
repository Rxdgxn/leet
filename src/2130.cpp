struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    int pairSum(ListNode* head) {
        int list[100001], k = 0, m = -1;

        while (head != nullptr) {
            list[k++] = head->val;
            head = head->next;
        }
        
        for (int i = 0; i <= (k / 2) - 1; i++) {
            int s = list[i] + list[k - i - 1];
            m = (m < s ? s : m);
        }

        return m;
    }
};