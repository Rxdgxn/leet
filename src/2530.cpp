#include "../include.h"

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie();

        priority_queue<int> pq;

        for (int n : nums) pq.push(n);

        long long ret = 0;

        while (k--) {
            const int x = pq.top();
            pq.pop();

            ret += x;
            
            pq.push(ceil(x / 3.0));
        }

        return ret;
    }
};