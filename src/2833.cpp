#include "../include.h"

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int free = 0, pos = 0;

        for (char& c : moves)
            if (c == 'L') pos--;
            else if (c == 'R') pos++;
            else free++;

        return free + abs(pos);
    }
};