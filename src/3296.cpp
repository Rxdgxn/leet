#include "../include.h"

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 0, r = 1e18;
        long long ret = 0;

        while (l <= r) {
            long long mid = (l + r) / 2;
            long long h = 0;

            for (int t : workerTimes) {
                h += (sqrt(1 + 8 * mid / t) - 1) / 2;

                if (h >= mountainHeight)
                    break;
            }

            if (h >= mountainHeight) {
                ret = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ret;
    }
};