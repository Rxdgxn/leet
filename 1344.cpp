#include "include.h"

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double degMin = minutes * 6.0;
        double degHour = minutes / 2.0 + 30 * (hour != 12 ? hour : 0);
        double ret = abs(degMin - degHour);
        
        return min(ret, 360 - ret);
    }
};