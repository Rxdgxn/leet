#include "include.h"

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ret(m);

        if (m * n != original.size()) return {};

        for (int i = 0; i < m; i++) {
            vector<int> tmp;
            for (int j = i * n; j < (i + 1) * n; j++) tmp.push_back(original[j]);
            ret[i] = tmp;
        }

        return ret;
    }
};