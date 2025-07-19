#include "../include.h"

class Solution {
public:
    int maxDistance(string s, int k) {
        int pdx = 0, pdy = 0, ndx = 0, ndy = 0;
        int iterations = 0, ret = 0;

        for (char c : s) {
            iterations++;

            if (c == 'N') pdy++;
            else if (c == 'S') ndy++;
            else if (c == 'W') ndx++;
            else pdx++;

            if (iterations >= k) {
                int saved_k = k;

                int minx = min(pdx, ndx);
                int maxx = max(pdx, ndx);

                int manh = maxx + 2 * min(k, minx) - minx;
                k -= min(k, minx);

                int miny = min(pdy, ndy);
                int maxy = max(pdy, ndy);

                manh += maxy + 2 * min(k, miny) - miny;

                ret = max(ret, manh);
                k = saved_k;
            }
        }

        return ret;
    }
};