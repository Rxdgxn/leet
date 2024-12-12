#include "../include.h"

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long total = 0;

        for (int g : gifts) {
            pq.push(g);
            total += g;
        }

        while (k--) {
            const int top = pq.top();
            pq.pop();

            const int taken = static_cast<int>(sqrt(top));
            pq.push(taken);

            total -= (top - taken);
        }

        return total;
    }
};