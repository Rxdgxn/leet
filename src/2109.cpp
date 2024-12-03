#include "../include.h"

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        const int n = s.size(), m = spaces.size();
        string ret(n + m, '\0');
        
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (i < m && spaces[i] == j) {
                ret[i + j] = ' ';
                i++;
            }

            ret[i + j] = s[j];
        }

        return ret;
    }
};