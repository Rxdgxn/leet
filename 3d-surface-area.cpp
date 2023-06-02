#include "include.h"

int marked[101][101];

int sq(vector<vector<int>> A, int i, int j) {
    int ret = 0;

    if (i > 0) {
        ret += (!marked[i-1][j] ? abs(A[i][j] - A[i-1][j]) : 0);
    }
    else {
        ret += A[i][j];
    }
    if (i < A.size() - 1) {
        ret += abs(A[i][j] - A[i+1][j]);
    }
    else {
        ret += A[i][j];
    }

    if (j > 0) {
        ret += (!marked[i][j-1] ? abs(A[i][j] - A[i][j-1]) : 0);
    }
    else {
        ret += A[i][j];
    }
    if (j < A[0].size() - 1) {
        ret += abs(A[i][j] - A[i][j+1]);
    }
    else {
        ret += A[i][j];
    }

    marked[i][j] = 1;

    return ret;
}

int surfaceArea(vector<vector<int>> A) {
    int h = A.size(), w = A[0].size(), area = 2 * h * w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            area += sq(A, i, j);
        }
    }

    return area;
}

int main(void) {

    int h, w;
    cin >> h >> w;
    vector<vector<int>> A;

    for (int i = 0; i < h; i++) {
        vector<int> tmp(w);
        for (int j = 0; j < w; j++) {
            cin >> tmp[j];
        }
        A.push_back(tmp);
    }

    cout << surfaceArea(A);

    return 0;
}