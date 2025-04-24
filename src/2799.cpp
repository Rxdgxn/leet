#include "../include.h"

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        const int n = nums.size();
        const int total_distinct = unordered_set<int>(nums.begin(), nums.end()).size();

        int ret = 0, right = 0;

        unordered_map<int, int> count;

        for (int left = 0; left < n; left++) {
            if (left > 0) {
                count[nums[left - 1]]--;

                if (count[nums[left - 1]] == 0)
                    count.erase(nums[left - 1]);
            }

            while (right < n && count.size() < total_distinct) {
                count[nums[right]]++;
                right++;
            }

            const int sz = count.size();

            if (sz == total_distinct)
                ret += n - right + 1;
            else if (sz < total_distinct)
                break;
        }

        return ret;
    }
};