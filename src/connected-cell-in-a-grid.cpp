#include "../include.h"

bool visited[10][10];
int cnt = 0;

void dfs(const vector<vector<int>>& matrix, int i, int j, int n, int m) {
    if (visited[i][j]) return;
    visited[i][j] = 1;
    cnt++;

    if (i < n - 1 && matrix[i + 1][j]) dfs(matrix, i + 1, j, n, m);
    if (i > 0 && matrix[i - 1][j]) dfs(matrix, i - 1, j, n, m);
    
    if (j < m - 1 && matrix[i][j + 1]) dfs(matrix, i, j + 1, n, m);
    if (j > 0 && matrix[i][j - 1]) dfs(matrix, i, j - 1, n, m);

    if (i < n - 1 && j < m - 1 && matrix[i + 1][j + 1]) dfs(matrix, i + 1, j + 1, n, m);
    if (i > 0 && j < m - 1 && matrix[i - 1][j + 1]) dfs(matrix, i - 1, j + 1, n, m);
    if (i < n - 1 && j > 0 && matrix[i + 1][j - 1]) dfs(matrix, i + 1, j - 1, n, m);
    if (i > 0 && j > 0 && matrix[i - 1][j - 1]) dfs(matrix, i - 1, j - 1, n, m);
}

int connectedCell(vector<vector<int>> matrix, int n, int m) {
    int ret = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] && !visited[i][j]) {
                dfs(matrix, i, j, n, m);
                ret = max(ret, cnt);
                cnt = 0;
            }
        }
    }

    return ret;
}

int main(void) {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    cout << connectedCell(matrix, n, m);

    return 0;
}