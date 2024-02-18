#include "../include.h"

class MountainArray {
public:
    int get(int k);
    int length();
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int p, l = 0, r = mountainArr.length() - 1;

        while (l != r) {
            p = l + (r - l) / 2;
            
            if (mountainArr.get(p) < mountainArr.get(p + 1)) l = p + 1;
            else r = p;
        }
        p = l;

        l = 0, r = p;
        while (l <= r) {
            int m = (l + r) / 2;
            const int e = mountainArr.get(m);
            
            if (target == e) return m;
            else if (target < e) r = m - 1;
            else l = m + 1;
        }

        l = p, r = mountainArr.length() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            const int e = mountainArr.get(m);
            
            if (target == e) return m;
            else if (target > e) r = m - 1;
            else l = m + 1;
        }

        return -1;
    }
};