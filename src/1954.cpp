#include "../include.h"

class Solution {
public:
    typedef long long ll;

    void extend(ll &curr_apples, ll &units) {
        units++;
        
        // After reducing a for loop using math
        curr_apples += 3 * units * (units + 1);
        curr_apples -= 2 * units;
    }

    inline ll calculate(ll apples, ll units) {
        return 4 * (apples - units * (units + 1) / 2);
    }

    ll minimumPerimeter(ll neededApples) {
        ll curr_apples = 0, units = 0;

        while (calculate(curr_apples, units) < neededApples) {
            extend(curr_apples, units);
        }

        return 8 * units;
    }
};