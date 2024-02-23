#include "../include.h"

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int dist = 0;

        while (mainTank) {
            int diff = min(mainTank, 5);

            if (diff == 5) {
                mainTank -= 5;

                dist += 50;

                if (additionalTank) {
                    additionalTank--;
                    mainTank++;
                }
            }
            else {
                mainTank -= diff;
                dist += diff * 10;
            }
        }

        return dist;
    }
};