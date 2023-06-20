#include "../include.h"

class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ret;
        char startCol = s[0], startRow = s[1], endCol = s[3], endRow = s[4];

        while (startCol <= endCol) {
            while (startRow <= endRow) {
                string x = "";
                x += startCol;
                x += startRow++;
                ret.push_back(x);
            }
            startRow = min(s[1], s[4]);
            startCol++;
            cout << endl;
        }

        return ret;
    }
};