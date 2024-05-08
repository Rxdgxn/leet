#include "../include.h"

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;

        const int n = score.size();
        
        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }

        vector<string> ret(n);
        int k = 1;

        while (!pq.empty()) {
            const int i = pq.top().second;

            if (k == 1) ret[i] = "Gold Medal";
            else if (k == 2) ret[i] = "Silver Medal";
            else if (k == 3) ret[i] = "Bronze Medal";
            else ret[i] = to_string(k);

            k++;
            pq.pop();
        }

        return ret;
    }
};