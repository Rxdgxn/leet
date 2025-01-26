#include "../include.h"

class Solution {
public:
    typedef long long ll;

    ll minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        ll c = 0;

        vector<vector<ll>> minCosts(26, vector<ll>(26, INT_MAX));

        for (int i = 0; i < original.size(); i++) {
            ll& location = minCosts[original[i] - 'a'][changed[i] - 'a'];
            location = min(location, static_cast<ll>(cost[i]));
        }

        for (int k = 0; k < 26; k++)
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    minCosts[i][j] = min(minCosts[i][j], minCosts[i][k] + minCosts[k][j]);

        for (int i = 0; i < source.size(); i++) {
            if (source[i] == target[i]) continue;

            ll& location = minCosts[source[i] - 'a'][target[i] - 'a'];
            if (location == INT_MAX) return -1;

            c += location;
        }


        return c;
    }
};