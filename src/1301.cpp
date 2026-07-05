#include "../include.h"

class Solution {
public:
    pair<int, int> maxScore[101][101]; // (score, paths)

    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int n = board.size();

        maxScore[n - 1][n - 1].first = maxScore[n - 1][n - 1].second = 1;

        for (int i = n - 2; i >= 0; i--) {
            if (board[n - 1][i] != 'X' && maxScore[n - 1][i + 1].first != 0) {
                maxScore[n - 1][i].first = maxScore[n - 1][i + 1].first + board[n - 1][i] - '0';
                maxScore[n - 1][i].second = 1;
            }
            else {
                maxScore[n - 1][i].first = 0;
                maxScore[n - 1][i].second = 0;
            }

            if (board[i][n - 1] != 'X' && maxScore[i + 1][n - 1].first != 0) {
                maxScore[i][n - 1].first = maxScore[i + 1][n - 1].first + board[i][n - 1] - '0';
                maxScore[i][n - 1].second = 1;
            }
            else {
                maxScore[i][n - 1].first = 0;
                maxScore[i][n - 1].second = 0;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                int m = 0, c = 0;

                for (auto it : {maxScore[i + 1][j], maxScore[i][j + 1], maxScore[i + 1][j + 1]}) {
                    if (it.second > 0) {
                        if (it.first > m) {
                            c = it.second;
                            m = it.first;
                        }
                        else if (it.first == m) {
                            c = ((long long)c + it.second) % (long long)(1e9 + 7);
                        }
                    }
                }

                if (c == 0) {
                    maxScore[i][j].first = maxScore[i][j].second = 0;
                    continue;
                }

                if (board[i][j] != 'X') {
                    maxScore[i][j].first = board[i][j] - '0' + m;
                    maxScore[i][j].second = c;
                }
                else {
                    maxScore[i][j].first = 0;
                    maxScore[i][j].second = 0;
                }
            }
        }

        int ways = maxScore[0][0].second;
        int bestScore = maxScore[0][0].first - 1 - 'E' + '0';

        if (ways == 0)
            return {0, 0};

        return {bestScore, ways};
    }
};