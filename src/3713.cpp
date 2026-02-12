#include "../include.h"

class Solution {
public:
    int longestBalanced(string s) {
        const int n = s.size();
        int ret = 1;

        for (int i = 0; i < n - 1; i++) {
            unordered_map<int, int> count, total_counts;

            count[s[i]]++;
            total_counts[1]++;

            for (int j = i + 1; j < n; j++) {
                int& curr_count = count[s[j]];

                if (curr_count > 0) {
                    total_counts[curr_count]--;

                    if (total_counts[curr_count] == 0)
                        total_counts.erase(curr_count);
                }

                curr_count++;
                total_counts[curr_count]++;

                if (total_counts.size() == 1)
                    ret = max(ret, j - i + 1);
            }



            if (ret >= n - i + 1)
                break;
        }

        return ret;
    }
};