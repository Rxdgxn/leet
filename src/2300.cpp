#include "../include.h"

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        const int n = spells.size();
        vector<int> ret(n);

        sort(potions.begin(), potions.end());

        for (int i = 0; i < n; i++) {
            long long min_quant = success / spells[i];

            if (min_quant * spells[i] < success)
                min_quant++;

            auto it = lower_bound(potions.begin(), potions.end(), min_quant);

            ret[i] = distance(it, potions.end());
        }

        return ret;
    }
};