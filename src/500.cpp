#include "../include.h"

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string rows[] = {
            "qwertyuiop",
            "asdfghjkl",
            "zxcvbnm"
        };

        vector<string> ret;

        for (string& word : words) {
            int row = 0, ok = 1;

            for (char ch : word) {
                ch = tolower(ch);

                if (rows[0].find(ch) != string::npos) {
                    if (!row) row = 1;
                    else if (row != 1) {
                        ok = 0;
                        break;
                    }
                }
                if (rows[1].find(ch) != string::npos) {
                    if (!row) row = 2;
                    else if (row != 2) {
                        ok = 0;
                        break;
                    }
                }
                if (rows[2].find(ch) != string::npos) {
                    if (!row) row = 3;
                    else if (row != 3) {
                        ok = 0;
                        break;
                    }
                }
            }

            if (ok) ret.push_back(word);
        }

        return ret;
    }
};