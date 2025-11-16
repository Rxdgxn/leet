#include "../include.h"

class Solution {
public:
    #define MOD 1000000007;

    int numSub(string s) {
        unordered_map<int, int> lengths;

        int l = 0;

        for (char c : s) {
            if (c == '1') {
                l++;
            }
            else if (l > 0) {
                lengths[l]++;
                l = 0;
            }
        }

        if (l > 0) {
            lengths[l]++;
        }

        int ret = 0;

        for (auto& [k, v] : lengths) {
            unsigned long long n = k;
            n = n * (n + 1) / 2;

            n *= v;

            ret += n % MOD;
        }

        return ret;
    }
};