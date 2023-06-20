#include "../include.h"

class Solution {
public:

    // Quite lazy

    inline short count(const vector<vector<int>>& board, int i, int j, const int m, const int n) {
        short nbrs = 0;
        nbrs += (i > 0 ? board[i-1][j] : 0);
        nbrs += (j > 0 ? board[i][j-1] : 0);
        nbrs += (i < m - 1 ? board[i+1][j] : 0);
        nbrs += (j < n - 1 ? board[i][j+1] : 0);
        nbrs += (i > 0 && j > 0 ? board[i-1][j-1] : 0);
        nbrs += (i > 0 && j < n - 1 ? board[i-1][j+1] : 0);
        nbrs += (i < m - 1 && j > 0 ? board[i+1][j-1] : 0);
        nbrs += (i < m - 1 && j < n - 1 ? board[i+1][j+1] : 0);
        return nbrs;
    }

    void gameOfLife(vector<vector<int>>& board) {
        const int m = board.size(), n = board[0].size();
        vector<vector<int>> trans = board;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                short nbrs = count(board, i, j, m, n);
                if (board[i][j]) {
                    if (nbrs < 2 || nbrs > 3) trans[i][j] = 0;
                }
                else {
                    if (nbrs == 3) trans[i][j] = 1;
                }
            }
        }

        board = trans;
    }
};