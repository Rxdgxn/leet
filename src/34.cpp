#include "../include.h"

class Solution {
public:
    vector<int> searchRange(const vector<int>& nums, int target) {
        vector<int> ret {-1, -1};

        const int sz = nums.size();
        int st = 0, dr = sz - 1, m;

        while (st <= dr) {
            m = (st + dr) / 2;
            if (nums[m] > target) dr = m - 1;
            else if (nums[m] < target) st = m + 1;
            else {
                int is = 0, id = 0;

                while (m - is >= 0 && nums[m - is] == target) is++;
                while (m + id < sz && nums[m + id] == target) id++;

                ret[0] = m - is + 1;
                ret[1] = m + id - 1;

                break;
            }
        }

        return ret;
    }
};