#include <stdbool.h>

bool checkSquare(int i, int j, char **board) {
    char f[10] = {0};

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (board[i + x][j + y] != '.') {
                if (f[board[i + x][j + y] - '0'])
                    return false;

                f[board[i + x][j + y] - '0'] = 1;
            }
        }
    }

    return true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    for (int i = 0; i < 9; i++) {
        char f[10] = {0};

        for (int j = 0; j < 9; j++)
            if (board[i][j] != '.') {
                if (f[board[i][j] - '0'])
                    return false;

                f[board[i][j] - '0'] = 1;
            }
    }

    for (int j = 0; j < 9; j++) {
        char f[10] = {0};

        for (int i = 0; i < 9; i++)
            if (board[i][j] != '.') {
                if (f[board[i][j] - '0'])
                    return false;

                f[board[i][j] - '0'] = 1;
            }
    }

    return checkSquare(0, 0, board) && checkSquare(0, 3, board) && checkSquare(0, 6, board) &&
            checkSquare(3, 0, board) && checkSquare(3, 3, board) && checkSquare(3, 6, board) &&
            checkSquare(6, 0, board) && checkSquare(6, 3, board) && checkSquare(6, 6, board);
}