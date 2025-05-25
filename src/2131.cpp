#include "../include.h"

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> occ, marked_keys;

        for (string& key : words)
            occ[key]++;

        int len = 0, max_odd_single = 0;
        vector<int> single_odds;

        bool checked = false;

        for (auto& [key, val] : occ) {
            if (marked_keys[key]) continue;

            string rev_key = key;
            swap(rev_key[0], rev_key[1]);

            if (rev_key != key) {
                len += (min(val, occ[rev_key]) << 2);
            }
            else {
                if (val % 2 == 1) {
                    if (checked) len += ((val - 1) << 1);
                    else len += (val << 1);

                    checked = true;
                }
                else {
                    len += (val << 1);
                }
            }

            marked_keys[rev_key] = 1;
        }

        return len;
    }
};