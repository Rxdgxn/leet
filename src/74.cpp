#include "../include.h"

class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        // Or could've just constructed a vector<int>
        int lm = 0, rm = matrix.size() - 1;

        while (lm <= rm) {
            const int mm = (lm + rm) / 2;
            if (matrix[mm][0] > target) {
                rm = mm - 1;
            }
            else if (matrix[mm][0] < target) {
                if (matrix[mm][matrix[0].size() - 1] > target) {
                    int l = 0, r = matrix[0].size() - 1;
                    while (l <= r) {
                        const int m = (l + r) / 2;
                        if (matrix[mm][m] < target) {
                            l = m + 1;
                        }
                        else if (matrix[mm][m] > target) {
                            r = m - 1;
                        }
                        else return true;
                    }
                    rm = mm - 1;
                }
                else if (matrix[mm][matrix[0].size() - 1] < target) {
                    lm = mm + 1;
                }
                else return true;
            }
            else return true;
        }

        return false;
    }
};