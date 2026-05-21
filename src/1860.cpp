#include "../include.h"

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int *mem = NULL;

        for (int t = 1; ; t++) {
            if (memory1 >= memory2)
                mem = &memory1;
            else
                mem = &memory2;
                
            if (*mem < t)
                return {t, memory1, memory2};

            *mem -= t;
        }

        return {};
    }
};