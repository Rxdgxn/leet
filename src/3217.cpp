#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numbers(nums.begin(), nums.end());

        ListNode *ret = NULL, *prev = NULL;

        while (head != NULL) {
            if (numbers.find(head->val) != numbers.end()) {
                ListNode *rem = head;

                if (prev != NULL) {
                    prev->next = head->next;
                }

                head = head->next;
            }
            else {
                if (ret == NULL) {
                    ret = head;
                }

                prev = head;
                head = head->next;
            }
        }

        return ret;
    }
};