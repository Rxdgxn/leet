#include "../include.h"

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int l = 0, r = tokens.size() - 1;
        int s = 0, m = 0;

        while (l <= r) {
            if (power >= tokens[l]) {
                power -= tokens[l];
                s++;
                m = max(m, s);
                l++;
            }
            else if (s > 0) {
                power += tokens[r];
                s--;
                r--;
            }
            else return m;
        }

        return m;
    }
};