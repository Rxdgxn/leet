#include "../include.h"

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level = 0;

        for (string& log : logs) {
            if (log == "../") level = max(0, level - 1);
            else if (log != "./") level++;
        }

        return level;
    }
};