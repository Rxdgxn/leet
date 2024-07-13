#include "../include.h"

class Solution {
public:
    // Simulation

    int findTheWinner(int n, int k) {
        vector<int> friends(n);

        for (int i = 1; i <= n; i++) friends[i - 1] = i;

        int i = 0;

        while (friends.size() > 1) {
            i = (i + k - 1) % friends.size();
            friends.erase(friends.begin() + i);
        }

        return friends[0];
    }
};