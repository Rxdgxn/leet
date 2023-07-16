#include "../include.h"

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        const int sz = code.size();
        if (k == 0) return vector<int>(sz, 0);

        auto copy = code;
        if (k > 0) {
            for (int i = 0; i < sz; i++) {
                int n = 0;
                for (int j = i + 1; j <= i + k; j++) {
                    n += copy[j >= sz ? j - sz : j];
                }
                code[i] = n;
            }
        }
        else {
            for (int i = 0; i < sz; i++) {
                int n = 0;
                for (int j = i - 1; j >= i + k; j--) {
                    n += copy[j < 0 ? sz + j : j];
                }
                code[i] = n;
            }
        }

        return code;
    }
};