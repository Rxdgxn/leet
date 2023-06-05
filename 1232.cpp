#include "include.h"

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int diffX = coordinates[1][0] - coordinates[0][0], diffY = coordinates[1][1] - coordinates[0][1];
        
        for (int i = 2; i < coordinates.size(); i++) {
            int dx = coordinates[i][0] - coordinates[0][0], dy = coordinates[i][1] - coordinates[0][1];
            if (diffX * dy != diffY * dx) return false;
        }

        return true;
    }
};