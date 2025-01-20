#include "../include.h"

class Solution {
public:
    char findKthBit(int n, int k) {
        string seq = "0";

        for (int i = 1; i < n && k > seq.size(); i++) {
            seq += '1';

            for (int j = seq.size() - 2; j >= 0; j--)
                seq += (seq[j] == '1' ? '0' : '1');
        }

        return seq[k - 1];
    }
};