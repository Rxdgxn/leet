#include "../include.h"

class CustomFunction {
public:
    int f(int x, int y);
};

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ret;

        for (int x = 1; x <= 1000; x++) {
            int l = 1, r = 1000, y;

            while (l <= r) {
                y = (l + r) / 2;
                const int t = customfunction.f(x, y);

                if (t == z) {
                    ret.push_back({x, y});
                    break;
                }
                else if (t > z) r = y - 1;
                else l = y + 1;
            }
        }

        return ret;
    }
};