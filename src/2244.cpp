#include "../include.h"

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> cnt;

        for (int t : tasks)
            cnt[t]++;

        int rounds = 0;

        for (auto& [t, c] : cnt) {
            if (c == 1)
                return -1;

            if (c % 3 == 0) {
                rounds += c / 3;
                continue;
            }

            if (c % 3 == 2) {
                rounds += c / 3 + 1;
                continue;
            }

            rounds += (c - 2) / 3 + 2;
        }

        return rounds;
    }
};