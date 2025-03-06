#include "../include.h"

class Solution {
public:
    int map[51 * 51] = {0};

    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long sum = 0;
        vector<int> ret(2);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                const int x = grid[i][j];

                if (map[x] == 0) {
                    map[x] = 1;
                    sum += x * x;
                }
                else ret[0] = x;
            }
        }

        n *= n;

        ret[1] = sqrt(n * (n + 1) * (2 * n + 1) / 6 - sum);

        return ret;
    }
};