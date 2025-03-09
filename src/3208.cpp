#include "../include.h"

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        const int n = colors.size();
        int c = 1, g = 0;

        for (int i = 0; i < n + k - 2; i++) {
            if (colors[i % n] ^ colors[(i + 1) % n]) {
                c++;
            }
            else {
                if (c >= k)
                    g += c - k + 1;

                c = 1;
            }
        }

        if (c >= k)
            g += c - k + 1;

        return g;
    }
};