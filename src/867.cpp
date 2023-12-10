#include "../include.h"

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        const int rows = matrix.size(), cols = matrix[0].size();

        auto trans = vector<vector<int>>(cols, vector<int>(rows));

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                trans[j][i] = matrix[i][j];

        return trans;
    }
};