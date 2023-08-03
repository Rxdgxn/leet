#include "../include.h"

class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0, late = 0, max_late = 0;

        for (char c : s) {
            if (c == 'L') late++;
            else {
                if (late) max_late = max(max_late, late);
                late = 0;
                if (c == 'A') absent++;
            }
        }

        max_late = max(max_late, late);
        return absent < 2 && max_late < 3;
    }
};