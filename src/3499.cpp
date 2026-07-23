#include "../include.h"

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> zero_sections;
        int n = s.size();

        int ones = s[0] - '0';
        int type = s[0], count = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                ones++;
            }

            if (s[i] == type) {
                count++;
            }
            else {
                if (type == '0') {
                    zero_sections.push_back(count);
                }

                type = s[i];
                count = 1;
            }
        }

        if (type == '0') {
            zero_sections.push_back(count);
        }

        int best = 0;
        n = (int)zero_sections.size() - 1;

        for (int i = 0; i < n; i++) {
            best = max(best, zero_sections[i] + zero_sections[i + 1]);
        }

        return ones + best;
    }
};