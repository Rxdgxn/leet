#include "../include.h"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        const int n = nums.size();
        int ret[10000], neg[10000], pos[10000];
        int s1, s2 = 0, i, j, k = 0;

        for (s1 = 0; s1 < n && nums[s1] < 0; s1++)
            neg[s1] = nums[s1] * nums[s1];

        for (int t = s1; t < n; t++)
            pos[s2++] = nums[t] * nums[t];

        i = s1 - 1;
        j = 0;

        while (i >= 0 && j < s2) {
            if (neg[i] < pos[j]) ret[k++] = neg[i--];
            else ret[k++] = pos[j++];
        }

        while (i >= 0) ret[k++] = neg[i--];
        while (j < s2) ret[k++] = pos[j++];

        return vector<int>(ret, ret + k);
    }
};