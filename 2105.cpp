#include "include.h"

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int l = 0, r = plants.size() - 1, t = 0, oa = capacityA, ob = capacityB;
        while (l < r) {
            if (capacityA < plants[l]) {
                t++;
                capacityA = oa;
            }
            if (capacityB < plants[r]) {
                t++;
                capacityB = ob;
            }
            capacityA -= plants[l];
            capacityB -= plants[r];
            l++;
            r--;
        }
        if (l == r) t += (max(capacityA, capacityB) < plants[l]);
        return t;
    }
};