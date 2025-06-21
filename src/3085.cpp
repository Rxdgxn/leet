#include "../include.h"

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freqs;

        for (char c : word) {
            freqs[c]++;
        }

        int ret = word.size();

        for (auto& [_, v1] : freqs) {
            int del = 0;

            for (auto& [_, v2] : freqs) {
                if (v2 < v1) {
                    del += v2;
                }
                else if (v2 > v1 + k) {
                    del += v2 - (v1 + k);
                }
            }

            ret = min(ret, del);
        }

        return ret;
    }
};