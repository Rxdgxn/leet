#include "../include.h"

class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int, int> lengths;
        stringstream ss(input);
        string curr;
        int max_len = 0;

        while (getline(ss, curr, '\n')) {
            int tabs = 0;
            const int sz = curr.size();

            while (curr[tabs] == '\t') tabs++;

            if (tabs == 0) lengths[tabs] = sz;
            else lengths[tabs] = lengths[tabs - 1] + sz - tabs + 1;

            if (curr.find('.') != string::npos) max_len = max(max_len, lengths[tabs]);
        }

        return max_len;
    }
};