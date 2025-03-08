#include "../include.h"

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int window = 0, m = INT_MAX, i;

        for (i = 0; i < k; i++)
            if (blocks[i] == 'W')
                window++;

        m = window;

        for (i = k; i < blocks.size(); i++) {
            if (blocks[i] == 'W')
                window++;
            
            if (blocks[i - k] == 'W')
                window--;

            m = min(m, window);
        }

        return m;
    }
};