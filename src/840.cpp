#include "../include.h"

class Solution {
public:
    int magic_sq = 0, kernel[3][3];

    void check() {
        unordered_set<int> s;
        int map[10] = {0};

        for (int i = 0; i < 3; i++) {
            int k1 = 0, k2 = 0;

            for (int j = 0; j < 3; j++) {
                if (kernel[i][j] == 0 || kernel[i][j] > 9 || map[kernel[i][j]]) return;
                map[kernel[i][j]] = 1;

                k1 += kernel[i][j];
                k2 += kernel[j][i];
            }

            s.insert(k1);
            s.insert(k2);
        }

        int k1 = 0, k2 = 0;

        for (int i = 0; i < 3; i++) {
            k1 += kernel[i][i];
            k2 += kernel[i][2 - i];
        }

        s.insert(k1);
        s.insert(k2);

        if (s.size() == 1) magic_sq++;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();

        if (rows * cols < 9) return 0;

        for (int i = 0; i < rows - 2; i++) {
            for (int j = 0; j < cols - 2; j++) {
                kernel[0][0] = grid[i][j];
                kernel[0][1] = grid[i][j + 1];
                kernel[0][2] = grid[i][j + 2];
                kernel[1][0] = grid[i + 1][j];
                kernel[1][1] = grid[i + 1][j + 1];
                kernel[1][2] = grid[i + 1][j + 2];
                kernel[2][0] = grid[i + 2][j];
                kernel[2][1] = grid[i + 2][j + 1];
                kernel[2][2] = grid[i + 2][j + 2];

                check();
            }
        }

        return magic_sq;
    }
};