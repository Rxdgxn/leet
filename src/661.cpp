#include "../include.h"

class Solution {
public:
    int m, n, count = 0;

    int val(const vector<vector<int>>& img, int i, int j) {
        if (i < 0 || j < 0 || i == m || j == n) return 0;

        count++;
        return img[i][j];
    }

    int average(const vector<vector<int>>& img, int i, int j) {
        int x = val(img, i, j) + val(img, i - 1, j) + val(img, i - 1, j - 1) + val(img, i - 1, j + 1) +
                val(img, i, j - 1) + val(img, i, j + 1) +
                val(img, i + 1, j - 1) + val(img, i + 1, j) + val(img, i + 1, j + 1);

        int k = count;
        count = 0;

        return x / k;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        m = img.size();
        n = img[0].size();

        vector<vector<int>> ret(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ret[i][j] = average(img, i, j);
            }
        }

        return ret;
    }
};