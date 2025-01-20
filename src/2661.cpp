#include "../include.h"

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int m = mat.size(), n = mat[0].size();

        unordered_map<int, int> rowOf, colOf;

        vector<int> coloredRow(m, 0), coloredCol(n, 0);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                rowOf[mat[i][j]] = i;
                colOf[mat[i][j]] = j;
            }

        for (int i = 0; i < arr.size(); i++) {
            const int& r = rowOf[arr[i]];
            const int& c = colOf[arr[i]];

            coloredRow[r]++;
            coloredCol[c]++;

            if (coloredRow[r] == n || coloredCol[c] == m) return i;
        }

        return -1;
    }
};