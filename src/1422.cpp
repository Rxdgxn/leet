#include "../include.h"

class Solution {
public:
    int maxScore(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int zeros[500], ones[500], m = 0;

        const int n = s.size();

        zeros[0] = (s[0] == '0');
        ones[0] = !zeros[0];

        for (int i = 1; i < n; i++) {
            zeros[i] = zeros[i - 1] + (s[i] == '0');
            ones[i] = ones[i - 1] + (s[i] == '1');
        }

        for (int i = 0; i < n - 1; i++) {
            m = max(m, zeros[i] + ones[n - 1] - ones[i]);
        }

        return m;
    }
};