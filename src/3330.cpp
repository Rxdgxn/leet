#include "../include.h"

class Solution {
public:
    int possibleStringCount(string word) {
        int strings = 1;
        char u = word[0];

        for (int i = 1; i < word.size(); i++) {
            if (word[i] == u) {
                strings++;
            }

            u = word[i];
        }

        return strings;
    }
};