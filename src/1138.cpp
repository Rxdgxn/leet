#include "../include.h"

class Solution {
public:
    const vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
    unordered_map<char, pair<int, int>> position;

    string alphabetBoardPath(string target) {
        for (int i = 0; i < board.size(); i++) {
            int j = 0;

            for (char c : board[i])
                position[c] = make_pair(i, j++);
        }

        int x = 0, y = 0;
        string ret;

        for (char c : target) {
            auto& p = position[c];
            char dir;

            if (make_pair(x, y) == position['z'] && c != 'z') {
                x--;
                ret += 'U';
            }

            // Match column first
            if (p.second > y) dir = 'R';
            else dir = 'L';

            int dist = abs(p.second - y);

            for (int i = 0; i < dist; i++)
                ret += dir;

            // Then row

            if (p.first > x) dir = 'D';
            else dir = 'U';

            dist = abs(p.first - x);

            for (int i = 0; i < dist; i++)
                ret += dir;


            x = p.first, y = p.second;

            ret += '!';
        }

        return ret;
    }
};