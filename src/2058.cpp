#include "../include.h"

struct ListNode {
    int val;
    ListNode *next;
};

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int l = -1, m = -1, r = -1, i = 0, first = -1, last = -1, prev = -1, curr = -1, min = INT_MAX;

        if (head != nullptr) {
            l = head->val;
            head = head->next;
            i++;
        }
        if (head != nullptr) {
            m = head->val;
            head = head->next;
            i++;
        }

        while (head != nullptr) {
            r = head->val;

            if ((l < m && m > r) || (l > m && m < r)) {
                if (first == -1) first = i;
                last = i;

                if (curr == -1) curr = i;
                else {
                    prev = curr;
                    curr = i;

                    min = std::min(min, curr - prev);
                }
            }

            l = m;
            m = r;

            head = head->next;
            i++;
        }

        if (l == -1 || m == -1 || r == -1 || prev == -1 || curr == -1) return {-1, -1};

        return {min, last - first};
    }
};