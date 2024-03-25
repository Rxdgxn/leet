#include "../include.h"

class Solution {
public:
    int count_set_bits(int n) {
        int b = 1;
        n = n & (n - 1);

        while (n) {
            n = n & (n - 1);
            b++;
        }
        
        return b;
    }

    bool canSortArray(vector<int>& nums) {
        vector<pair<int, int>> v;

        for (int x : nums)
            v.push_back({x, count_set_bits(x)});

        int s;

        do {
            s = 1;

            for (int i = 0; i < nums.size() - 1; i++)
                if (v[i].first > v[i + 1].first) {
                    if (v[i].second != v[i + 1].second) return false;
                    swap(v[i], v[i + 1]);
                    s = 0;
                }

        } while (s == 0);

        return true;
    }
};