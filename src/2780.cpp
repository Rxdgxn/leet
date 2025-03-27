#include "../include.h"

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        const int n = nums.size();

        vector<int> beg(n), end(n);
        unordered_map<int, int> counter;

        int dom = -1;

        for (int i = 0; i < n; i++) {
            counter[nums[i]]++;

            const int curr_len = (i + 1) / 2;

            if (counter[nums[i]] > curr_len)
                dom = nums[i];
            else if (counter[dom] <= curr_len)
                dom = -1;

            beg[i] = dom;
        }

        dom = -1;
        counter.clear();

        for (int i = n - 1; i >= 0; i--) {
            counter[nums[i]]++;

            const int curr_len = (n - i) / 2;

            if (counter[nums[i]] > curr_len)
                dom = nums[i];
            else if (counter[dom] <= curr_len)
                dom = -1;

            end[i] = dom;
        }

        for (int i = 0; i < n - 1; i++)
            if (beg[i] == end[i + 1] && beg[i] != -1)
                return i;

        return -1;
    }
};