#include "../include.h"

class Solution {
public:
    unordered_map<int, int> memo;

    int coinChange(vector<int>& coins, int amount) {
        if (amount < 0)
            return -1;

        if (amount == 0)
            return 0;

        if (memo.find(amount) != memo.end())
            return memo[amount];

        int m = INT_MAX;

        for (int c : coins) {
            int cg = coinChange(coins, amount - c);

            if (cg != -1)
                m = min(m, cg);
        }

        if (m == INT_MAX) {
            memo[amount] = -1;
            return -1;
        }

        return memo[amount] = m + 1;
    }
};