#include "../include.h"

class Solution {
public:
    typedef unsigned long long ull;

    int maxProfit(vector<int>& inventory, int orders) {
        const ull MOD = 1e9 + 7;

        priority_queue<ull> pq(inventory.begin(), inventory.end());
        pq.push(0);

        ull ret = 0;
        ull ball_count = 0;

        while (orders > 0) {
            ull ball_value = pq.top();

            while (pq.top() == ball_value) {
                ball_count++;
                pq.pop();
            }

            ull next_value = pq.top();
            ull hops = (ball_value - next_value);
            ull count = ball_count * hops;
            ull one_sum = (ball_value * (ball_value + 1) - next_value * (next_value + 1)) / 2;

            if (orders >= count) {
                ret = (ret + ball_count * one_sum) % MOD;
                orders -= count;
            }
            else {
                ull full = orders / ball_count;
                ull rest = orders % ball_count;

                ull low = ball_value - full;
                ull s = (ball_value * (ball_value + 1) - low * (low + 1)) / 2;
                ret = (ret + ball_count * s) % MOD;

                ret = (ret + rest * low) % MOD;

                break;
            }
        }

        return (int)ret;
    }
};