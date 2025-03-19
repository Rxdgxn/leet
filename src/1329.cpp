#include "../include.h"

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        priority_queue<int, vector<int>, greater<int>> pq;

        const int m = mat.size(), n = mat[0].size();

        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0, k = i; j < n && k < m; j++, k++)
                pq.push(mat[k][j]);

            for (int j = 0, k = i; j < n && k < m; j++, k++) {
                mat[k][j] = pq.top();
                pq.pop();
            }
        }

        for (int j = 1; j < n; j++) {
            for (int i = 0, k = j; i < m && k < n; i++, k++)
                pq.push(mat[i][k]);

            for (int i = 0, k = j; i < m && k < n; i++, k++) {
                mat[i][k] = pq.top();
                pq.pop();
            }
        }

        return mat;
    }
};