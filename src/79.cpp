#include "../include.h"

class Solution {
public:
    int bs, b0s, ws;
    string word;

    bool find_word(const vector<vector<char>>& board, int it, int i, int j, vector<vector<bool>>& visited) {
        if (it == ws) return true;

        if (i < 0 || j < 0 || i == bs || j == b0s) return false;
        if (board[i][j] != this->word[it]) return false;
        if (visited[i][j]) return false;

        visited[i][j] = true;

        auto x = find_word(board, it + 1, i + 1, j, visited) 
        || find_word(board, it + 1, i, j + 1, visited) 
        || find_word(board, it + 1, i - 1, j, visited)
        || find_word(board, it + 1, i, j - 1, visited);

        visited[i][j] = false;

        return x;
    } 

    bool exist(vector<vector<char>>& board, string word) {
        bs = board.size(), b0s = board[0].size(), ws = word.size();
        this->word = word;
        
        for (int i = 0; i < bs; i++) {
            for (int j = 0; j < b0s; j++) {
                auto visited = vector<vector<bool>>(7, vector<bool>(7, 0));
                if(find_word(board, 0, i, j, visited)) return true;
            }
        }

        return false;
    }
};