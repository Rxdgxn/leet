#include "../include.h"

class Solution {
public:
    map<pair<char, char>, vector<char>> triangles;
    bool check = false;

    void back(int begin_index, int row_size, string& row, string& new_row) {
        if (check)
            return;

        if (new_row.size() == row_size - 1) {
            if (new_row.size() == 1) {
                check = true;
                return;
            }

            string next_row;
            back(0, row_size - 1, new_row, next_row);
            return;
        }

        for (char possible_char : triangles[make_pair(row[begin_index], row[begin_index + 1])]) {
            new_row.push_back(possible_char);
            back(begin_index + 1, row_size, row, new_row);

            if (check)
                return;

            new_row.pop_back();
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (string& t : allowed)
            triangles[make_pair(t[0], t[1])].push_back(t[2]);

        const int n = bottom.size();
        string new_string;

        back(0, n, bottom, new_string);

        return check;
    }
};