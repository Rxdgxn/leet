#include "../include.h"

class Solution {
public:

    int v[201];

    void dfs(int i, const vector<vector<int>>& isConnected) {
        v[i] = 1;
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[i][j] && !v[j]) {
                dfs(j, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int t = 0;

        for (int i = 0; i < isConnected.size(); i++) {
            if (!v[i]) {
                t++;
                dfs(i, isConnected);
            }
        }

        return t;
    }
};