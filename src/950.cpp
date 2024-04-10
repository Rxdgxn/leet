#include "../include.h"

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        const int n = deck.size();
        
        queue<int> q;

        for (int i = 0; i < n; i++)
            q.push(i);

        vector<int> ret(n);
        for (int i = 0; i < n; i++) {
            ret[q.front()] = deck[i];
            q.pop();

            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return ret;
    }
};