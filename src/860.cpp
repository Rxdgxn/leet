#include "../include.h"

class Solution {
public:
    enum BILLS {
        FIVE = 0,
        TEN
    };

    bool lemonadeChange(vector<int>& bills) {
        int map[2] = { 0 };

        for (int bill : bills) {
            if (bill == 5) map[FIVE]++;
            else if (bill == 10) {
                if (map[FIVE] == 0) return false;
                
                map[FIVE]--;
                map[TEN]++;
            }
            else {
                if (!(map[FIVE] >= 3 || (map[TEN] && map[FIVE]))) return false;

                if (map[TEN] && map[FIVE]) {
                    map[TEN]--;
                    map[FIVE]--;
                }
                else map[FIVE] -= 3;
            }
        }

        return true;
    }
};