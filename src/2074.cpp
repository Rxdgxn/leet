#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie();

        auto curr = head;
        vector<int> arr;

        while (curr != nullptr) {
            arr.push_back(curr->val);
            curr = curr->next;
        }

        const int n = arr.size();

        int len = 0;
        for (int i = 0; i < n; i += len) {
            len++;
            int remaining = n - i;

            int q = min(remaining, len);

            if (q % 2 == 0)
                reverse(arr.begin() + i, arr.begin() + i + q);
        }

        ListNode *mut = new ListNode(-1);

        for (int i = n - 1; i >= 0; i--) {
            if (mut->val < 0) mut->val = arr[i];
            else {
                ListNode* tmp = new ListNode(arr[i], mut);
                mut = tmp;
            }
        }

        return mut;
    }
};