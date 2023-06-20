#include "../include.h"

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size(), b = 1;

        for (int i = 0; i < n && b; i++) {
            int r[101] = {0}, c[101] = {0};
            for (int j = 0; j < n; j++) {
                if (r[matrix[i][j]]) {
                    b = 0;
                    break;
                }
                r[matrix[i][j]] = 1;
                if (c[matrix[j][i]]) {
                    b = 0;
                    break;
                }
                c[matrix[j][i]] = 1;
            }
        }

        return b;
    }
};