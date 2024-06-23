#include "../include.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> win;

        int st = 0, dr = 0, n = nums.size(), m = 0;;

        while (dr < n) {
            win.insert(nums[dr]);

            while (*win.rbegin() - *win.begin() > limit) {
                win.erase(win.find(nums[st++]));
            }

            m = max(m, dr - st + 1);

            dr++;
        }

        return m;
    }
};