#include "include.h"

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int k[1001] = {0};
        for (auto p : trust) {
            k[p[0]]--;
            k[p[1]]++;
        }

        for (int i = 1; i <= n; i++)
            if (k[i] == n - 1) return i;
        
        return -1;
    }
};