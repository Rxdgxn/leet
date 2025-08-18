#include "../include.h"

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int final_energy = INT_MIN;
        const int n = energy.size();

        vector<int> dp(n);

        for (int i = n - 1; i >= 0; i--) {
            if (i + k < n)
                dp[i] = dp[i + k] + energy[i];
            else
                dp[i] = energy[i];

            final_energy = max(final_energy, dp[i]);
        }

        return final_energy;
    }
};