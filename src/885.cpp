#include "../include.h"

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ret;

        int visited = 1, count = 1;
        const int to_visit = rows * cols;

        ret.push_back({rStart, cStart});

        while (visited != to_visit) {
            for (int i = 0; i < count; i++) {
                cStart++;
                
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    ret.push_back({rStart, cStart});
                    visited++;
                }
            }
            for (int i = 0; i < count; i++) {
                rStart++;
                
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    ret.push_back({rStart, cStart});
                    visited++;
                }
            }

            count++;

            for (int i = 0; i < count; i++) {
                cStart--;
                
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    ret.push_back({rStart, cStart});
                    visited++;
                }
            }
            for (int i = 0; i < count; i++) {
                rStart--;
                
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    ret.push_back({rStart, cStart});
                    visited++;
                }
            }
            
            count++;
        }

        return ret;
    }
};