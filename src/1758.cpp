#include "../include.h"

class Solution {
public:
    int minOperations(string s) {
        int o0 = 0, o1 = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                if (s[i] == '0') o1++;
                else o0++;
            }
            else {
                if (s[i] == '1') o1++;
                else o0++;
            }
        }
        
        return min(o0, o1);
    }
};