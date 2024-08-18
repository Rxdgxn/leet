#include "../include.h"

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        const int n = hand.size();
        if (n % groupSize) return false;

        map<int, int> cards;

        for (int i = 0; i < n; i++) cards[hand[i]]++;

        while (!cards.empty()) {
            int c = cards.begin()->first;

            for (int i = 0; i < groupSize; i++) {
                if (cards[c + i] == 0) return false;
                
                cards[c + i]--;

                if (cards[c + i] < 1) cards.erase(c + i);
            }
        }

        return true;
    }
};