#include "../include.h"

class Solution {
public:
    int m, n;

    // Quite ugly
    int count_bombs(vector<vector<char>>& board, int i, int j) {
        int b = 0;

        if (i > 0) {
            if (board[i - 1][j] == 'M')
                b++;

            if (j > 0 && board[i - 1][j - 1] == 'M')
                b++;
            if (j < n - 1 && board[i - 1][j + 1] == 'M')
                b++;
        }
        if (i < m - 1) {
            if (board[i + 1][j] == 'M')
                b++;

            if (j > 0 && board[i + 1][j - 1] == 'M')
                b++;
            if (j < n - 1 && board[i + 1][j + 1] == 'M')
                b++;
        }

        if (j > 0 && board[i][j - 1] == 'M') b++;
        if (j < n - 1 && board[i][j + 1] == 'M') b++;

        return b;
    }

    void reveal(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] != 'E') return;

        const int bombs = count_bombs(board, i, j);

        if (bombs != 0) board[i][j] = (bombs + '0');
        else {
            board[i][j] = 'B';

            if (i > 0) {
                if (board[i - 1][j] == 'E')
                    reveal(board, i - 1, j);

                if (j > 0 && board[i - 1][j - 1] == 'E')
                    reveal(board, i - 1, j - 1);
                if (j < n - 1 && board[i - 1][j + 1] == 'E')
                    reveal(board, i - 1, j + 1);
            }
            if (i < m - 1) {
                if (board[i + 1][j] == 'E')
                    reveal(board, i + 1, j);

                if (j > 0 && board[i + 1][j - 1] == 'E')
                    reveal(board, i + 1, j - 1);
                if (j < n - 1 && board[i + 1][j + 1] == 'E')
                    reveal(board, i + 1, j + 1);
            }

            if (j > 0 && board[i][j - 1] == 'E') reveal(board, i, j - 1);
            if (j < n - 1 && board[i][j + 1] == 'E') reveal(board, i, j + 1);
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();

        int i = click[0], j = click[1];

        if (board[i][j] == 'M') {
            board[i][j] = 'X';
            return board;
        }

        reveal(board, i, j);
        return board;
    }
};