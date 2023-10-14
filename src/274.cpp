#include "../include.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int it = 1, h = 0;

        priority_queue<int> pq;
        unordered_map<int, int> mp;
        
        for (int c : citations) pq.push(c);

        while (!pq.empty()) {
            const int t = pq.top();
            mp[t]++;

            h = max(h, min(it, t));

            pq.pop();
            it++;
        }

        return h;
    }
};