#include "../include.h"

class Spreadsheet {
public:
    vector<vector<int>> sheet;

    Spreadsheet(int rows) {
        sheet = vector<vector<int>>(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;

        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);
    }

    int eval(char *p) {
        string s = p;

        // cell ref
        if ('A' <= s[0] && s[0] <= 'Z') {
            int col = s[0] - 'A';
            int row = stoi(s.substr(1)) - 1;

            return sheet[row][col];
        }

        // number
        return stoi(s);
    }
    
    int getValue(string formula) {
        char *p = strtok((char*)formula.c_str(), "+=");

        int first = eval(p);
        p = strtok(NULL, "+=");
        int second = eval(p);

        return first + second;
    }
};