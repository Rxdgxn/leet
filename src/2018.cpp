#include "../include.h"

class Solution {
public:
    bool matchWords(string& pattern, string& word) {
        if (pattern.size() != word.size())
            return false;

        for (int i = 0; i < pattern.size(); i++)
            if (pattern[i] == ' ')
                continue;
            else if (pattern[i] != word[i])
                return false;

        return true;
    }

    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        string rev = word;
        reverse(rev.begin(), rev.end());

        const int m = board.size(), n = board[0].size();

        // Vertical matches
        for (int col = 0; col < n; col++) {
            string w;

            for (int row = 0; row < m; row++) {
                if (board[row][col] == '#') {
                    if (matchWords(w, word) || matchWords(w, rev)) {
                        return true;
                    }

                    w.clear();
                }
                else {
                    w.push_back(board[row][col]);
                }
            }

            if (matchWords(w, word) || matchWords(w, rev)) {
                return true;
            }
        }

        // Horizontal matches
        for (int row = 0; row < m; row++) {
            string w;

            for (int col = 0; col < n; col++) {
                if (board[row][col] == '#') {
                    if (matchWords(w, word) || matchWords(w, rev)) {
                        return true;
                    }

                    w.clear();
                }
                else {
                    w.push_back(board[row][col]);
                }
            }

            if (matchWords(w, word) || matchWords(w, rev)) {
                return true;
            }
        }

        return false;
    }
};