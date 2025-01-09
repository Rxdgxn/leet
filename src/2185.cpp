#include "../include.h"

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int c = 0;
        const int n = pref.size();

        for (const string& word : words) {
            if (word.substr(0, n) == pref) {
                c++;
            }
        }

        return c;
    }
};